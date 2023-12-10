class Solution {
public:
    int countTestedDevices(vector<int> &b) {
        int n = b.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(b[i]!=0){
                if(b[i]-cnt>0) cnt++;
            }
        }
        return cnt;
    }
};