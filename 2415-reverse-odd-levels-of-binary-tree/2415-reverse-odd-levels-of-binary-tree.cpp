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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swit= false; 
        while(!q.empty()){
            vector<int> values;
            vector<TreeNode*> Nodes; 
            int size= q.size();
            
            for(int i=0; i< size; i++){
                TreeNode* tmp= q.front();
                q.pop();
                Nodes.push_back(tmp);
                values.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }

            if(swit) {
                reverse(values.begin(), values.end());
                for(int i=0; i< values.size(); i++){
                    Nodes[i]->val= values[i];
                }
            }
            swit =!swit;
        }
        return root;
    }
};