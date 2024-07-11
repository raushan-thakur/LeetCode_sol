class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>index;
        string res = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                index.push(i);
            }
            else if(s[i] == ')'){
                int to = index.top();
                index.pop();
                reverse(s.begin() + to + 1, s.begin() + i);
            }
        }
        for (char c : s) {
            if (c != '(' && c != ')') {
                res += c;
            }
        }

        return res;
    }
};