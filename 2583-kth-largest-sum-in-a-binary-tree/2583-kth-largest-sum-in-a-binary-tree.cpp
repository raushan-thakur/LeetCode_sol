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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long s = 0;
            while(n--){
                TreeNode* qf = q.front();
                q.pop();
                s += qf->val;
                if(qf->left) q.push(qf->left);
                if(qf->right) q.push(qf->right);
            }
            sum.push_back(s);
            push_heap(sum.begin(), sum.end());
        }
        if(k > sum.size()) return -1;
        while(--k){
            pop_heap(sum.begin(), sum.end());
            sum.pop_back();
        }
        return sum.front();
    
    }
};