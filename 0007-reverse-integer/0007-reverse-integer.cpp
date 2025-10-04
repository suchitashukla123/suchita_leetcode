class Solution {
public:
    int reverse(int x) {
        long rev = 0;  // use long to detect overflow during computation
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            rev = rev * 10 + digit;
            
            // check for overflow
            if (rev > INT_MAX || rev < INT_MIN)
                return 0;
        }
        
        return (int)rev;
    }
};