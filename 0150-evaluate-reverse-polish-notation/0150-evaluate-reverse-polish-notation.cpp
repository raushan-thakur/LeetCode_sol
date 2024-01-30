class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                
                int ans = 0;
                if(s == "+") ans = a+b;
                if(s == "-") ans = a-b;
                if(s == "*") ans = a*b;
                if(s == "/") ans = a/b;
        
                stack.push(ans);
                
            } else {
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};