class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> a(26);
        for (auto i : s) a[i - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (a[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};