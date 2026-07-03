class Solution {
public:
    string reverseVowels(string s) {
        unordered_set <char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0;
        int  right = s.size()-1;
        while(left<right){
            if(vowel.count(s[left])){
                if(vowel.count(s[right])){
                    swap(s[left] , s[right]);
                    left++;
                    right--;
                }
                else{
                    right--;
                }
            }
            else{
                left++;
            }
        }
        return s;   
    }
};