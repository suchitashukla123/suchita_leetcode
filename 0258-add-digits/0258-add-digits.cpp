class Solution {
public:
    int addDigits(int num) {
        int total = 0;
        while (num > 0) {
            int rem = num % 10;
            total += rem;
            num = num / 10;
        }
        if (total > 9) {
            return addDigits(total);
        }
        return total;
    }
};
