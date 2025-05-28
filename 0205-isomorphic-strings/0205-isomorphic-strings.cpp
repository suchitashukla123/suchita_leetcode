class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mpp;
        unordered_map<char, char> reverse_mpp;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check if there's already a mapping
            if (mpp.count(c1)) {
                if (mpp[c1] != c2) return false;
            } else {
                // Check reverse mapping to ensure one-to-one mapping
                if (reverse_mpp.count(c2)) {
                    if (reverse_mpp[c2] != c1) return false;
                }
                mpp[c1] = c2;
                reverse_mpp[c2] = c1;
            }
        }

        return true;
    }
};
