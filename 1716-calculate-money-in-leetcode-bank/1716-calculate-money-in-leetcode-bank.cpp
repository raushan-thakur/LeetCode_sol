class Solution {
public:
    int totalMoney(int n) {
        
        int x = n/7;
        
        int ans =0;
        int count =0;
        
        for(int i = 0 ; i<= x; i++){
            for(int j =1+i; j<=7+i; j++){
                if(count++<n)
                    ans+=j;
                else break;
            }
        }
        return ans;
    }
};