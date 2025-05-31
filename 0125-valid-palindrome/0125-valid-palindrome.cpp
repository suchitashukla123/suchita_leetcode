class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0; i<s.size();i++){
            s[i]=tolower(s[i]);
            if(!isalnum(s[i])){
                s.erase(i,1);
                i--;
            }
        }
        int l=0, r=s.size()-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};