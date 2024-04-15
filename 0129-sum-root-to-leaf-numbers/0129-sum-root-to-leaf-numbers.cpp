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
    void solve(TreeNode* root, int& ans, int num){
        if(root == NULL) return;
        

        num  = num*10 + root->val;
        solve(root->left, ans, num);
        if(root->left == NULL && root->right == NULL){
            ans+=num;
            return;
        }
        solve(root->right, ans, num);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};