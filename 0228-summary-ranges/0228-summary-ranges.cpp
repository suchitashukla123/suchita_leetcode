class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;

        int start = nums[0];
        for (int i = 1; i <= n; i++) {
            // When we reach the end or the sequence breaks
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1])
                    res.push_back(to_string(start));
                else
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                if (i < n) start = nums[i];
            }
        }
        return res;
    }
};
