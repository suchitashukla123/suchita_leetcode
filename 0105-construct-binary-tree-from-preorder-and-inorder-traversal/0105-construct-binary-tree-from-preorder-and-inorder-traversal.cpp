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
    unordered_map<int, int> inorderIndex;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Pre-store indexes for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preStart = 0;
        return build(preorder, 0, inorder.size() - 1, preStart);
    }

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd, int& preStart) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart++];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];

        // Recursively build left and right subtrees
        root->left = build(preorder, inStart, idx - 1, preStart);
        root->right = build(preorder, idx + 1, inEnd, preStart);

        return root;
    }
};
