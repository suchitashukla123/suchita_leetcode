class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Tsum=0;
        for(int i=0;i<=nums.size();i++){
            Tsum+=i;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return Tsum-sum;
        
    }
};