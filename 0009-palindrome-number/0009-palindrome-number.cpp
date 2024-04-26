class Solution {
public:
    bool isPalindrome(int n) {
        int ans = 0;
        int x = n;
        if(x<0 || (x!=0 && x%10 == 0) ) return 0;
       
        while(x){
            int rem = x%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
             ans = ans*10+rem;
            x=x/10;
        }
        cout<<ans<<endl;
        return ans == n;
    }
};