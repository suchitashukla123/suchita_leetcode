class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin() , s.end());
        vector<int> freq(26 , 0);
        for(char c : s){
            freq[c-'a']++;
        }
        string left = "" , mid = "" ;
        for(int i = 0 ; i<26 ; i++){
            left += string( freq[i]/2 , char('a' + i));
            if(freq[i] % 2){
                mid = char('a' + i);
            }
        }
        string right = left;
        reverse(right.begin() , right.end());

        return left + mid + right;
        
    }
};