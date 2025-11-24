class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Clamped per problem requirement
        
        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to avoid overflow when converting INT_MIN
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        int result = 0;

        // Subtract divisor multiples using bit shifts
        while (a >= b) {
            long long temp = b;
            int multiple = 1;

            // Double until too large
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};
