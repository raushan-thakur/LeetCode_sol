class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int maxi = INT_MIN;
        for(int i=0;i<values.size();i++){
            int val = values[i];
            ans = max(ans,maxi+val-i);
            maxi = max(maxi,val+i);
        }
        return ans;
    }
};