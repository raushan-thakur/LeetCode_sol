class Solution {
public:
    string getLCP(string s1, string s2) {
        string lcp = "";
        int i = 0, j = 0;
        while (s1[i] == s2[j]) {
            lcp += s1[i];
            i++;
            j++;
        }
        return lcp;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (string &str : folder) {
            if (ans.size()) {
                string last = ans.back() + "/";
                string lcp = getLCP(str, last);
                if (lcp == last)
                    continue;
                ans.push_back(str);
            } else {
                ans.push_back(str);
            }
        }
        return ans;
    }
};