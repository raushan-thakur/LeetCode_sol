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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        while(!q.empty()){
           int size=q.size();
           int prev=0;
           if(count%2){
               prev = 0;
               for(int i=0; i<size; i++){
               auto node = q.front();
               q.pop();
                   if(node->val <= prev || node->val%2==0){
                       return false;
                   }else{
                       prev = node->val;
                       if(node->left) q.push(node->left);
                       if(node->right) q.push(node->right);
                   }
               }
               count++;
           }else{
               prev = 1e9;
               for(int i=0; i<size; i++){
               auto node = q.front();
               q.pop();
                   if(node->val >= prev || node->val%2){
                       return false;
                   }else{
                       prev = node->val;
                       if(node->left) q.push(node->left);
                       if(node->right) q.push(node->right);
                   }
               }
               count++;
           }
        }
        return true;
    }
};