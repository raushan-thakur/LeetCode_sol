class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> p;
        
        for(int i =0; i<s.length(); i++){
            if(s[i] == '(') p.push(i);
            else if(s[i] == '*') st.push(i);
            else{
                if(!p.empty()) p.pop();
                else if (!st.empty()) st.pop();
                else return false;
            }
        }
        
        while(!p.empty()){
            if(st.empty()) return false;
             if(st.top()<p.top()) return false;
            p.pop();
            st.pop();
        }
        return true;
    }
};
