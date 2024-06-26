class Solution {
public:
    bool isSafe(int row, int col, vector<string>& ds){
        int r = row;
        int c = col;
        
        while(col>=0){
            if(ds[row][col] == 'Q') return false;
            col--;
        }
        
        col = c;
        while(col>=0 && row>=0){
            if(ds[row][col] == 'Q') return false;
            col--;
            row--;
        }
        
        col = c;
        row = r;
        while(col>=0 && row<ds.size()){
            if(ds[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& ds, int& ans){
        if(col == n){
            ans++;
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, ds)){
                ds[row][col] = 'Q';
                solve(col+1, n, ds, ans);
                ds[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        
        string s;
        for(int i =0;i <n; i++) s.push_back('.');
        vector<string> ds(n,s);
        
        solve(0, n, ds, ans);
        return ans;
    }
};