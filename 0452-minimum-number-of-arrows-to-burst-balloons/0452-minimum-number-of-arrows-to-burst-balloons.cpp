class Solution {
public:
    static bool cmp( vector<int>& a,  vector<int>& b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        
        int cnt = 1; 
        int endPos = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] > endPos) { 
                cnt++;
                endPos = points[i][1];
            }
        }
        return cnt;
    }
};
