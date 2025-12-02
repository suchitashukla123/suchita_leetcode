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
    struct Info {
        bool perfect;
        int height;
        int size;
    };

    vector<int> perfectSizes;

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, 0, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        bool isPerfect = left.perfect && right.perfect && (left.height == right.height);

        int height = max(left.height, right.height) + 1;
        int size = left.size + right.size + 1;

        if (isPerfect) {
            perfectSizes.push_back(size);
        }

        return {isPerfect, height, size};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);

        if (perfectSizes.size() < k)
            return -1;

        sort(perfectSizes.begin(), perfectSizes.end(), greater<int>());

        return perfectSizes[k - 1];
    }
};
