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
    void dfs(TreeNode* root, int val, int depth, int currdepth){
        if(!root) return;
        
        if(currdepth<depth-1){
            dfs(root->left, val, depth, currdepth+1);
            dfs(root->right, val, depth, currdepth+1);
        }
        if(currdepth == depth-1){
            TreeNode* exLeftChild = root->left;
            TreeNode* exRightChild = root->right;
            TreeNode* leftChild = new TreeNode(val);
            TreeNode* rightChild = new TreeNode(val);
            
            root->left = leftChild;
            leftChild->left = exLeftChild;
            root->right = rightChild;
            rightChild->right = exRightChild;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newChild = new TreeNode(val);
            newChild->left = root;
            return newChild;
        }
        dfs(root, val, depth, 1);
        return root;
    }
};