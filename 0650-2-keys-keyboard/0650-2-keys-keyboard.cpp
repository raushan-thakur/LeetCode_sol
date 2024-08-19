class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        while(n > 1){
            for(int i=n/2; i>=1; i--){
                if(n % i == 0){
                    ans += (n/i);
                    n = i;
                    break;
                }
            }
        }
        return ans;
    }
};