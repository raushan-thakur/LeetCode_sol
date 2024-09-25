class trie {
    public:
    trie* next[26] = {};
    int wordCount;
    trie(){
        wordCount = 0;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* root = new trie();
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            auto cur = root;
            for (char c : words[i]) {
                if (!cur -> next[c - 'a'])
                    cur -> next[c - 'a'] = new trie();
                cur = cur -> next[c - 'a'];
                cur -> wordCount++;
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto cur = root;
            for (int j = 0; j < words[i].size(); j++) {
                cur = cur -> next[words[i][j] - 'a'];
                ans[i] += cur -> wordCount;
            }
        }
        
        return ans;
    }
};