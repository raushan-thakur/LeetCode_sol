class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> laser;
        
        for(int i =0 ;i<n;i++){
            int cnt = 0;
            for(int j=0; j < bank[i].size(); j++){
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt)
            laser.push_back(cnt);
        }
        
        int ans = 0;
        
        for(int i=1; i<laser.size() ; i++){
            int prev = laser[i-1];
            int next = laser[i];
            ans+= (prev*next);
        }
        return ans;
    }
};