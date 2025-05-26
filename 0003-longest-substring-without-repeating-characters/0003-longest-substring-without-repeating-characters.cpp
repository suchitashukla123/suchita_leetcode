class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, maxlen = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
