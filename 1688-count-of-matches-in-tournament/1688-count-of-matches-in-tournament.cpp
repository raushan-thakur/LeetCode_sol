class Solution {
public:
    int numberOfMatches(int n) {
        
        int ans = 0;
        
        while(n>1){
            if(n%2 ==0){
                n=n/2;
                ans+=n;
            }else{
                n=n/2;
                ans+=n;
                n=n+1;
            }
                
        }
        return ans ;
    }
};