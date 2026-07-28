class Solution {
public:
    bool checkpalindrome(string &s , int left , int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right =  s.size()-1;
        while(left < right ){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return checkpalindrome(s , left+1 , right)||checkpalindrome(s , left , right-1);

            }
        }
        return true;
    }
};