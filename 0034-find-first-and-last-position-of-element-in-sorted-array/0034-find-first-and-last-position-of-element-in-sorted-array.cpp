class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int low = 0 ;
        int high = nums.size()-1;
        int ans1 = -1;
        int ans2 = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]==target){
                ans1 = mid;
                high = mid-1;
            }
            else if( nums[mid] < target ){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans.push_back(ans1);
        low = 0;
        high = nums.size() - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]==target){
                ans2 = mid;
                low = mid+1;
            }
            else if( nums[mid] < target ){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans.push_back(ans2);
        return ans;
    }
};