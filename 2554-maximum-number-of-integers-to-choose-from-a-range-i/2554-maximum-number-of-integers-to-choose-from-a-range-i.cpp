class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> mpp;
        for(auto it: banned){
            mpp[it]++;
        }
        int count=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(mpp.find(i)!=mpp.end()) continue;
            else{
                sum+=i;
                if(sum<=maxSum){
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};