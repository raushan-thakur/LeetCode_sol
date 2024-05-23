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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int first = q.front().second;
            int last;
            int sz = q.size();
            for(int i =0; i<sz; i++){
                if(i==sz-1) last = q.front().second;
                TreeNode* front = q.front().first;
                long long l = q.front().second - first;
                q.pop();
                
                if(front->left){
                    q.push({front->left, 2*l+1});
                }
                if(front->right){
                    q.push({front->right, 2*l+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};