class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;              // pointer for next 0
        int mid = 0;              // current element
        int high = nums.size()-1; // pointer for next 2

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
