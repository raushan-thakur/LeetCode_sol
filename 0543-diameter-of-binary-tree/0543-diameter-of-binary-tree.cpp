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
    pair<int, int> f(TreeNode* root) {
        if (root == NULL) return {0, 0};

        auto left = f(root->left);
        auto right = f(root->right);

        int cD = max(left.second + right.second, 
                                  max(left.first, right.first));

        int cH = max(left.second, right.second) + 1;

        return {cD, cH};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).first;
    }
};