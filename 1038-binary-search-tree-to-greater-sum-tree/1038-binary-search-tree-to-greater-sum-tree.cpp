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
    void traversal(TreeNode* root, unsigned long long& sum) {

        if (!root) {
            return;
        }

        traversal(root->right, sum);

        sum += root->val;
        root->val = sum;

        traversal(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        unsigned long long sum = 0;
        traversal(root, sum);
        return root;
    }
};