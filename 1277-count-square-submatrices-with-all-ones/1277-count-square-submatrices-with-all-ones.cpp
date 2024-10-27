class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int s=0;
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++)
                if(mat[i][j]) mat[i][j]+=min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1]);
        }
        for(auto i:mat)
            for(auto j:i) s+=j;
        return s;
    }

};