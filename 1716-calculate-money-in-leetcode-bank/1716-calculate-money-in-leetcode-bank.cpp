class Solution {
public:
    int totalMoney(int n) {
        
        int monday = n/7;
        
        int ans =0;
        int count =0;
        
        for(int i = 0 ; i<= monday; i++){
            for(int j =1; j<=7; j++){
                if(count++<n)
                    ans+=j+i;
                else break;
            }
        }
        return ans;
    }
};