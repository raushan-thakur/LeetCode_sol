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
    TreeNode* findTarget(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &ntp){
        ntp[root] = NULL;
        TreeNode* target = NULL;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front->val == start) target = front;
            if(front->left){
                ntp[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                ntp[front->right] = front;
                q.push(front->right);
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> ntp;
        TreeNode* target = findTarget(root, start, ntp);
        unordered_map<TreeNode*, bool> v;
        v[target] = 1;
        queue<TreeNode* > q;
        q.push(target);
        int time = 0;
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* front  = q.front();
                q.pop();
                if(front->left && !v[front->left]){
                    flag = 1;
                    v[front->left] = 1;
                    q.push(front->left);
                }
                if(front->right && !v[front->right]){
                    flag = 1;
                    v[front->right] = 1;
                    q.push(front->right);
                }
                if(ntp[front] && !v[ntp[front]]){
                    flag =1;
                    v[ntp[front]]=1;
                    q.push(ntp[front]);
                }
            }
            if(flag) time++;
        }
        return time;
    }
};