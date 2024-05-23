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
    TreeNode* mapToParent(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                if(node->val == start) res= node;
                q.pop();
                if(node->left){
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return res;
    }
    int solve(TreeNode* res, unordered_map<TreeNode*, TreeNode*>& mp){
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(res);
        vis[res] = 1;
        int ans =0;
        
        while(!q.empty()){
            int sz = q.size();
            int flag =0;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    flag =1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    flag =1;
                    vis[node->right] =1;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){
                    flag =1;
                    vis[mp[node]] =1;
                    q.push(mp[node]);
                }
            }
            if(flag ==1) ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* res = mapToParent(root, start, mp);
        
        return solve(res, mp);
    }
};