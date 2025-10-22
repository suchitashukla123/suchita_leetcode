class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;           // edge case: no zigzagging
        int n = s.size();
        vector<string> rows(min(numRows, n)); // one string per row

        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow].push_back(c);
            // change direction when we hit top or bottom row
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        // concatenate rows
        string result;
        result.reserve(n);
        for (const string &r : rows) result += r;
        return result;
    }
};
