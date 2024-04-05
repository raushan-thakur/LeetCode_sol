class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto it : s) {
            if(!st.empty() && ((it -'A'== st.top() -'a' ) || (it -'a'== st.top() -'A'))){
                st.pop();
            }else{
                st.push(it);
            }
        }
        
        string ans= "";

        while(!st.empty()){
            char top = st.top();
            st.pop();
            ans = top + ans;
        }
        return ans;
    }
};