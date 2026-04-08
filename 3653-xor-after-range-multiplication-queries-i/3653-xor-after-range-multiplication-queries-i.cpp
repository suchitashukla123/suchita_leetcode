class Solution {
public:
    static const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        // Group small k queries
        unordered_map<int, vector<vector<int>>> mp;

        for (auto &q : queries) {
            if (q[2] <= B)
                mp[q[2]].push_back(q);
            else {
                // Large k → brute force
                for (int i = q[0]; i <= q[1]; i += q[2]) {
                    nums[i] = (1LL * nums[i] * q[3]) % MOD;
                }
            }
        }

        // Process small k
        for (auto &[k, qs] : mp) {
            vector<vector<pair<int,long long>>> updates(k);

            for (auto &q : qs) {
                int l = q[0], r = q[1], v = q[3];
                int rem = l % k;

                int start = (l - rem) / k;
                int end = (r - rem) / k;

                updates[rem].push_back({start, v});
                updates[rem].push_back({end + 1, modInverse(v)});
            }

            for (int rem = 0; rem < k; rem++) {
                vector<int> idx;
                for (int i = rem; i < n; i += k)
                    idx.push_back(i);

                int sz = idx.size();
                vector<long long> mul(sz + 1, 1);

                for (auto &[pos, val] : updates[rem]) {
                    if (pos < sz)
                        mul[pos] = mul[pos] * val % MOD;
                }

                for (int i = 1; i < sz; i++) {
                    mul[i] = mul[i] * mul[i - 1] % MOD;
                }

                for (int i = 0; i < sz; i++) {
                    nums[idx[i]] = nums[idx[i]] * mul[i] % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }

    long long power(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }
};