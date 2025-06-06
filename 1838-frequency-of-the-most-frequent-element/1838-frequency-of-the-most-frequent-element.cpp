class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long total=0;
        int l=0, maxfreq=0;
        for(int r=0;r<nums.size();r++){
            total+=nums[r];
            while((long)nums[r]*(r-l+1)-total>k){
                total-=nums[l];
                l++;
            }
            maxfreq=max(maxfreq,r-l+1);

        }
        return maxfreq;

        
    }
};