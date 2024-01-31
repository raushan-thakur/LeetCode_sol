class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        int n = t.size();
        vector<int> a(n, 0);
        vector<int> s;

        for (int i = n - 1; i >= 0; --i) {
            int cT = t[i];

            while (!s.empty() && cT >= t[s.back()]) {
                s.pop_back();
            }

            if (!s.empty()) a[i] = s.back() - i;
            
            s.push_back(i);
        }

        return a;
    }
};