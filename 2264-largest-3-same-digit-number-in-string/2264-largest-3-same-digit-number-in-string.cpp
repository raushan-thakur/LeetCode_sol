class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 0; i< num.length()-2; i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                if((num[i])>(ans[0])){
                        ans=num[i] ;
                        ans+=num[i] ;
                        ans+=num[i] ;
                } 
            }
        }
       return ans; 
    }
};