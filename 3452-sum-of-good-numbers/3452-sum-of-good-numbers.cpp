class Solution {
public:
    int sumOfGoodNumbers(const vector<int>& nums, int k) {
        const int n = nums.size();
        long long sum = 0; // long long just to be safe
        for (int i = 0; i < n; ++i) {
            bool left_ok  = (i - k < 0) || (nums[i] > nums[i - k]);   // either left index doesn't exist, or nums[i] > nums[i-k]
            bool right_ok = (i + k >= n) || (nums[i] > nums[i + k]); // same for right
            if (left_ok && right_ok) sum += nums[i];
        }
        return (int)sum;
    }
};
