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
    TreeNode* findLCA(TreeNode* root, int s, int e){
        if(root == NULL) return root;
        if(root->val == s || root->val == e) return root;
        
        TreeNode* l = findLCA(root->left, s, e);
        TreeNode* r = findLCA(root->right, s, e);
        
        if(l&&r) return root;
        
        return l?l:r;
    }
    bool findPath(string& p, TreeNode* root, int x){
        if(root == NULL) return false;
        if(root->val == x) return true;
        
        p+='L';
        bool l = findPath(p, root->left, x);
        if(l) return true;
        
        p.pop_back();
        
        p+='R';
        bool r = findPath(p, root->right, x);
        if(r) return true;
        
        p.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        cout<<lca->val<<endl;
        string l="",r="";
        
        findPath(l,lca,startValue);
        for(auto &it:l) it = 'U';
        findPath(r, lca, destValue);
        
        string ans=l+r;
        return ans;
    }
};