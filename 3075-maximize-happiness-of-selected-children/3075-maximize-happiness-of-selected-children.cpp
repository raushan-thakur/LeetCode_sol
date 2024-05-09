class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int t = 0;
        int n = h.size();
        sort(h.begin(), h.end());
        long long ans = 0;
        for(int i = n-1; i>=n-k; i--){
            long long x = h[i]-t++;
            if(x > 0)
                ans+= x;
        }
        return ans;
    }
};