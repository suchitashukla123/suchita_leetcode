/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);
        targetSum -= root->val;

        // If it's a leaf and the sum matches, store the path
        if (!root->left && !root->right && targetSum == 0) {
            result.push_back(path);
        }

        // Recurse left and right
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};
