class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> usedInteger;
        while(true){
            int sum=0;
            while(n!=0){
                int digit=n%10;
                sum+=pow(digit,2);
                n=n/10;
            }
            if(sum==1){
                return true;
            }
            if(usedInteger.count(sum)){
                return false;
            }
            usedInteger.insert(sum);
            n=sum;
        }
        
    }
};