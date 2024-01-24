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
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == NULL) return 0;
        
        count[root->val]++;

        int value = 0;
        if ((root->left == NULL) && (root->right == NULL)) {
            if (check()) value = 1;
            else value = 0;
        }
        else {
            value = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        }
        count[root->val]--;

        return value;
    }
private:
    int count[10] = {0};
    bool check() {
        int oddCount = 0;
        for (int i = 1; i <= 9; i++) {
            if ((count[i] & 1) == 1) oddCount++;
        }
        return oddCount <= 1;
    }
};