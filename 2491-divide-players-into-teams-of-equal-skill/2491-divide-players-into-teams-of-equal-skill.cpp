class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int s = 2 * accumulate(skill.begin(), skill.end(), 0) / skill.size();
        long long ans = 0;
        
        unordered_map<long long, int> cnt;
        for (int n : skill) ++cnt[n];
        
        for (auto[v,c] : cnt)
            if (!cnt.count(s-v) || cnt[s-v] != c)
                return -1;
            else
                ans += c * v * (s-v);
        
        return ans/2;
    }
};
