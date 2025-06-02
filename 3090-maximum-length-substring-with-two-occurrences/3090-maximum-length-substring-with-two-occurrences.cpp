class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,maxlen=0;
        unordered_map<char ,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp[s[r]]>2){
                mpp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        
    }
    return maxlen;
    }
};