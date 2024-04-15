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
    void solve(TreeNode* root, int& ans, int currSum){
        if(!root) return;
        
        currSum  = currSum*10 + root->val;
        solve(root->left, ans, currSum);
        if(!root->left && !root->right){
            ans+=currSum;
            return;
        }
        solve(root->right, ans, currSum);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};