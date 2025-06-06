class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            // If current value is less than the next one, we subtract
            if (i + 1 < s.length() && m[s[i]] < m[s[i + 1]]) {
                total -= m[s[i]];
            } else {
                total += m[s[i]];
            }
        }

        return total;
    }
};
