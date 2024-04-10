class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        int n = d.size();
        vector<int> ans(n,0);
        sort(d.begin(), d.end());
        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        int i =0;
        while(!q.empty()){
            int start = q.front();
            q.pop();
            ans[start] = d[i++];
            int end = q.front();
            q.pop();
            q.push(end);
        }
        return ans;
    }
};