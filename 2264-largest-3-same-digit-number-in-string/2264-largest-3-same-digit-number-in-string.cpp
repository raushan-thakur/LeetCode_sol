class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 1; i< num.length()-1; i++){
            if(num[i-1]==num[i] && num[i]==num[i+1]){
                if(ans.length() == 0){
                    ans=num[i] ;
                    ans+=num[i] ;
                    ans+=num[i] ;
                }else{
                    if((num[i] -'0')>(ans[0] - '0')){
                        ans=num[i] ;
                        ans+=num[i] ;
                        ans+=num[i] ;
                    }
                }
                
            }
        }
       return ans; 
    }
};