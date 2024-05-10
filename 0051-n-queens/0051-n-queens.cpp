class Solution {
public:
    void solve(int col, int n, vector<string>& ds, vector<vector<string>>& ans, vector<int>& rowCheck, vector<int>& upDCheck, vector<int>& downDCheck){
        if(col == n){
            ans.push_back(ds);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(!rowCheck[row] && !upDCheck[row+col] && !downDCheck[n-1+col-row]){
                rowCheck[row] = 1;
                upDCheck[row+col] = 1;
                downDCheck[n-1+col-row] = 1;
                ds[row][col] = 'Q';
                solve(col+1, n, ds, ans, rowCheck, upDCheck, downDCheck);
                ds[row][col] = '.';
                rowCheck[row] = 0;
                upDCheck[row+col] = 0;
                downDCheck[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> rowCheck(n,0);
        vector<int> upDCheck(2*n-1,0);
        vector<int> downDCheck(2*n-1,0);
        string s;
        for(int i =0;i <n; i++) s.push_back('.');
        vector<string> ds(n,s);
        
        solve(0, n, ds, ans, rowCheck, upDCheck, downDCheck);
        return ans;
    }
};