class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_length = INT_MAX;
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        while(right< n){
                sum +=  nums[right];
            while(sum >= target ){
                int length = right-left+1;
                min_length = min( min_length , length);
                sum -= nums[left];
                left++;
                
            }
            right++;

        }

        return (min_length == INT_MAX) ? 0 : min_length;
    }
};