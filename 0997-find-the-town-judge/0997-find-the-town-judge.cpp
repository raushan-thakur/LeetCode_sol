class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n + 1, 0); 

        for (auto i : trust) {
            trustcount[i[0]]--;  
            trustcount[i[1]]++;  
        }
        for (int i = 1; i <= n; ++i)
            if (trustcount[i] == n - 1) return i;
        
        return -1; 
    }
};