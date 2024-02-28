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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftNodeVal = root->val;
        
        while(!q.empty()){
            int n = q.size();
            int orgSize = n;
            while(n-->0){
                
                TreeNode * curr = q.front();
                q.pop();
                
                if(orgSize-1 == n)
                    leftNodeVal = curr->val;
                if(curr->left != NULL)q.push(curr->left);
                if(curr->right != NULL)q.push(curr->right);
            }
        }   
        return leftNodeVal;
    }
};