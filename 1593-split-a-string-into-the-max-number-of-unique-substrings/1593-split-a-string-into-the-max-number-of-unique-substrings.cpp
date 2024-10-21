class Solution {
public:
    void solve(string s, int idx, unordered_set<string> &st, int curr, int& mx){
        if(curr + (s.length() - idx) <= mx){
            return;
        }

        if(idx == s.length()){
            mx = max(mx, curr);
        }

        for(int j = idx ; j < s.length(); j++){
            string sub = s.substr(idx, j-idx+1);

            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(s, j+1, st, curr+1, mx);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int max_count = 0;
        int current = 0;

        solve(s, 0, st, current, max_count);

        return max_count;        
    }
};