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
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        if(root == NULL) return root;
        
        if(root->left) {
            TreeNode* x =removeLeafNodes(root->left, t);
            root->left = x;
        }
        if(root->right) {
            TreeNode* x = removeLeafNodes(root->right, t);
            root->right = x;
        }
        
        if(root->left == NULL && root->right ==NULL && root->val == t) return NULL;
        return root;
    }
};