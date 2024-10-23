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
    void get_ans(TreeNode*root,int d,vector<int>&arr){
        if(!root) return;
        if(root->left || root->right){
            int temp=arr[d+1];
            if(root->left)temp-=root->left->val;
            if(root->right) temp-=root->right->val;
            if(root->left) root->left->val=temp;
            if(root->right) root->right->val=temp;
        }
        get_ans(root->left,d+1,arr);
        get_ans(root->right,d+1,arr);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>arr;
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode*tope=q.front();
            q.pop();
            if(tope) ans+=tope->val;
            if(tope==NULL){
             arr.push_back(ans);
             ans=0;
             if(!q.empty()) q.push(NULL);
            }
            else{
                if(tope->right) q.push(tope->right);
                if(tope->left) q.push(tope->left);
            }
        }
        if(root) root->val=0;
        get_ans(root,0,arr);
        return root;
    }
};