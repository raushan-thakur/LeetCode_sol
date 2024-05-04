class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return b[1] > a[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        int cnt=1;
        int last = pairs[0][1];
        
        for(int i =1; i<pairs.size(); i++){
            if(pairs[i][0] > last){
                last = pairs[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};