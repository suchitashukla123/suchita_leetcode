class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        istringstream iss(s);
        vector<string> words;
        string w;
        while (iss >> w) {
            words.push_back(w);
        }
        if (words.size() != n) return false;

        vector<int> charIndex(128, 0);  
        unordered_map<string, int> wordIndex;

        for (int i = 0; i < n; ++i) {
            char c = pattern[i];
            string &word = words[i];

        
            if (charIndex[c] != wordIndex[word]) {
                return false;
            }
           
            charIndex[c] = i + 1;
            wordIndex[word] = i + 1;
        }
        return true;
    }
};
