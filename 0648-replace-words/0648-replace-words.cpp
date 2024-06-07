class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        sort(d.begin(), d.end());

        string ans = "";
        int l = 0;
        int flag = 0;

        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                if (flag == 0) ans += s.substr(l, i - l);
                ans += ' ';
                l = i + 1;
                flag = 0;
                continue;
            }
            string x = s.substr(l, i - l + 1);
            if (flag == 0 && find(d.begin(), d.end(), x) != d.end()) {
                ans += x;
                flag = 1;
            }
        }
        
        if (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};