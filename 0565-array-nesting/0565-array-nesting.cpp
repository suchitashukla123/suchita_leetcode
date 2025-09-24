class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) continue;
            int cur = i;
            int len = 0;
            while (nums[cur] != -1) {
                int next = nums[cur];
                nums[cur] = -1; // mark as visited
                cur = next;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
