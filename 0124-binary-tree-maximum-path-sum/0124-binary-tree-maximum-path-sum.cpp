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
    int maxSum(TreeNode* root, int&maxi){
        if(root == NULL) return 0;
        
        int leftSum = maxSum(root->left, maxi);
        int rightSum = maxSum(root->right, maxi);
        
        maxi = max(maxi, leftSum+rightSum+root->val);
        
        return max(0, root->val + max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int sum = maxSum(root, maxi);
        return maxi;
    }
};