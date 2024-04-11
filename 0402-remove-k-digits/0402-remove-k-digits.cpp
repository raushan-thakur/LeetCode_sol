class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k) return "0";
        stack<char> st;
        for(int i =0; i<n ;i++){
            while(!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k--){
            st.pop();
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top() ;
            st.pop();
        }
        
        int cnt =0 ;
        for(int i=ans.size()-1; i>=0 ;i--){
            if(ans[i] != '0'){
                cnt = i;
                break;
            }
        }
        
        ans = ans.substr(0, cnt+1);
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0) return "0";
            return ans;
        
    }
};