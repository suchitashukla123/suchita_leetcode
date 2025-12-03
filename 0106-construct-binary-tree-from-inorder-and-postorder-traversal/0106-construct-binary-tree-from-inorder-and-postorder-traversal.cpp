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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.empty()) return nullptr;
        int n = inorder.size();
        // build map: value -> index in inorder
        for (int i = 0; i < n; ++i) idx[inorder[i]] = i;
        // start from the last index of postorder (root)
        postIndex = n - 1;
        return build(0, n - 1, postorder);
    }

private:
    unordered_map<int,int> idx;
    int postIndex;

    // build subtree for inorder range [inLeft, inRight]
    TreeNode* build(int inLeft, int inRight, const vector<int>& postorder) {
        if (inLeft > inRight) return nullptr;

        // current root value is postorder[postIndex]
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // find root's index in inorder to split left/right
        int inRootIndex = idx[rootVal];

        // IMPORTANT: build right subtree first because we are moving
        // from end of postorder to beginning (root, then right, then left)
        root->right = build(inRootIndex + 1, inRight, postorder);
        root->left  = build(inLeft, inRootIndex - 1, postorder);

        return root;
    }
};