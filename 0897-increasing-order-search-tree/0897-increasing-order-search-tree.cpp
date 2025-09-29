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
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);

        TreeNode* dummy = new TreeNode(-1); 
        TreeNode* curr = dummy;
        
        for (int v : vals) {
            curr->right = new TreeNode(v);
            curr = curr->right;
        }

        return dummy->right;
        
    }
};