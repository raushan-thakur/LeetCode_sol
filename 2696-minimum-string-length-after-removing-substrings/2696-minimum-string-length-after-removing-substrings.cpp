class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(!st.empty()){
                if(ch == 'B' && st.top() == 'A' || ch == 'D' && st.top() == 'C'){
                    st.pop();
                }
                else st.push(ch);
            }
            else{
                st.push(ch);
            }
        }

        return st.size();
    }
};