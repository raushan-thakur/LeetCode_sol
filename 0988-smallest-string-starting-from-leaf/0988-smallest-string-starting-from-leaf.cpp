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
    string ans = "";
    void dfs(TreeNode* root, string& s){
        if(!root) return;
        
        s+=('a' + root->val);
        
        if(!root->left && !root->right){
            reverse(s.begin(), s.end());
            if(ans.length() == 0) ans= s;
            else ans = min(ans, s);
            reverse(s.begin(), s.end());
        }
        
        dfs(root->left, s);
        dfs(root->right, s);
        
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root, s);
        return ans;
    }
};