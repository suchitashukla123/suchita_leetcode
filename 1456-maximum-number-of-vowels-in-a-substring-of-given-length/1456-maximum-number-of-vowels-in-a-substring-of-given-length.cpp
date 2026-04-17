class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c=='e'|| c=='i' || c== 'o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int count = 0 , max_count = 0;
        for(int i=0 ; i<k ; i++){
            if(isVowel(s[i])) count++;
        }

        max_count=count;

        for(int i=k ; i<s.length() ; i++){
            if(isVowel(s[i-k])) count--;

            if(isVowel(s[i])) count++;

            max_count = max(max_count , count);
        }
         return max_count;
        
    }
};