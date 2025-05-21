class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ct++;
                maxi=max(maxi,ct);
            }
            else{
                ct=0;
            }
        }
        return maxi;
        
    }
};