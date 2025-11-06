class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        unsigned mask = 0;
        int temp = n;
        while (temp) {
            mask = (mask << 1) | 1; // make mask like 111...
            temp >>= 1;
        }

        return n ^ mask; // XOR flips all bits within mask
    }
};
