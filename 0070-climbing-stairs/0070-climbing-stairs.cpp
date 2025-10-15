class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1; // ways for 0 or 1 as base
        int b = 1; // ways for 1
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};