/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode* leftN = solve(root->left, p, q);
        TreeNode* rightN = solve(root->right, p, q);
        
        
        if(leftN != NULL && rightN != NULL) return root;
        if(leftN) return leftN;
        return rightN;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return solve(root, p, q);
        
        while(root){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }else {
                return root;
            }
        }
        return root;
    }
};