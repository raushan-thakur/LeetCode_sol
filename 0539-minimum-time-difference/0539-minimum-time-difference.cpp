class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        int mi = 100000;
        for (auto& i : timePoints) {
            int min2 = (i[0] - '0') * 10 + i[1] - '0';
            int min1 = (i[3] - '0') * 10 + i[4] - '0';
            v.push_back(min2 * 60 + min1);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            if (mi > v[i + 1] - v[i]) {
                mi = (v[i + 1] - v[i]);
            }
        }
        if (v[0] < 720) {
            int mint=-v[v.size()-1]+v[0]+1440;
            if (mi > mint) {
                mi = mint;
            }
        }
        return mi;
    }
};