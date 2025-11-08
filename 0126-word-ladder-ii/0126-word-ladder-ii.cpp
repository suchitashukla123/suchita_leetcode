class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        // For tracking paths: child -> list of parents
        unordered_map<string, vector<string>> parent;
        unordered_set<string> current{beginWord};
        bool found = false;
        int L = beginWord.size();

        while (!current.empty() && !found) {
            // Remove words already used at this level
            for (auto& w : current) dict.erase(w);
            unordered_set<string> next;

            for (auto& word : current) {
                string temp = word;
                for (int i = 0; i < L; ++i) {
                    char old = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == old) continue;
                        temp[i] = c;

                        if (!dict.count(temp)) continue;  // only consider words still in dict

                        parent[temp].push_back(word);      // record parent for backtracking
                        next.insert(temp);

                        if (temp == endWord) found = true; // stop after this level
                    }
                    temp[i] = old;
                }
            }
            current.swap(next);
        }

        vector<vector<string>> result;
        if (found) {
            vector<string> path{endWord};
            backtrack(endWord, beginWord, parent, path, result);
        }
        return result;
    }

private:
    void backtrack(const string& word,
                   const string& beginWord,
                   unordered_map<string, vector<string>>& parent,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(move(temp));
            return;
        }
        for (auto& p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parent, path, result);
            path.pop_back();
        }
    }
};
