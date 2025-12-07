class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;
    vector<vector<int>> dp; // -1 = unknown, 0 = false, 1 = true
    
    bool isPalindrome(const string &s, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r]; // return cached result
        
        while (l < r) {
            if (s[l] != s[r]) 
                return dp[l][r] = 0;
            l++; 
            r--;
        }
        return dp[l][r] = 1;
    }

    void backtrack(const string &s, int start) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        
        backtrack(s, 0);
        return result;
    }
};
