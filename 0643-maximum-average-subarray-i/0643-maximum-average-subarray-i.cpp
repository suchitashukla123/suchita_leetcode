class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0 ,maxavg=0,sum=0;
        for(int i=0;i<k;i++ ){
            sum+=nums[i];        
        }
        avg=sum/k;
        maxavg=avg;
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k]+nums[i];
            avg=sum/k;
            maxavg=max(maxavg,avg);
        }
        return maxavg;
    }
};