class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int ans = INT_MIN;
        for(int i=1; i<p.size(); i++){
            int diff = p[i][0] - p[i-1][0];
            if(diff>ans)    ans = diff;
        }
        return ans;
    }
};