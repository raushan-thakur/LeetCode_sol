/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root,vector<int> &post){
        if(!root) return;
        for(auto it:root->children){
            dfs(it,post);
        }
        post.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> post;
        dfs(root,post);
        return post;
    }
};