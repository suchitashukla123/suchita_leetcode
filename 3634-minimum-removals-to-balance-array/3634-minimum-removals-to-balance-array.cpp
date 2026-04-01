class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            
            // condition break -> move left
            while ((long long)nums[right] > (long long)k * nums[left]) {
                left++;
            }

            // valid window length
            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};