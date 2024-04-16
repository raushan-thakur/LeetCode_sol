class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        
        int sum = 0;
        for(int i=0; i<k; i++){
            sum+=c[i];
        }
        int x=1;
        int maxSum = sum;
        for(int i=k-1; i>=0; i--){
            sum-=c[i];
            sum+=c[n-x++];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};