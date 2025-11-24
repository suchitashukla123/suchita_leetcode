class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long to avoid abs(INT_MIN) overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;

        // Use bit shifting to speed up subtraction
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double temp until it exceeds 'a'
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Apply sign
        result = negative ? -result : result;

        // Clamp to int range (should not overflow here)
        return (int)result;
    }
};
