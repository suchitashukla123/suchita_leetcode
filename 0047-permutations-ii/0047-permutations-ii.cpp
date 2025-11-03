class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // sorting helps group duplicates
        backtrack(nums, 0, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> used; // to track duplicates at this recursion depth
        
        for (int i = start; i < nums.size(); ++i) {
            // skip duplicates at the same recursion level
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            
            swap(nums[start], nums[i]);             // fix one element
            backtrack(nums, start + 1, res);        // recurse on the rest
            swap(nums[start], nums[i]);             // backtrack
        }
    }
};

