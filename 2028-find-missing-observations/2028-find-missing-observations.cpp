class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int i = 0;i<m;i++) sum += rolls[i];
        
        int left = (mean * (n + m)) - sum;
        if(ceil((double)left/n) > 6 || left < 0 || left < n) return {};
    
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = left/n;
        }
        
        int left_val = left % n;
        for(int i = 0;i<left_val;i++){
            ans[i]++;
        }
        
        return ans;
    }
};