class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>a;
        for(auto c: s) a[c]++;

        priority_queue<pair<int, char>> pq;
        
        for(auto x: a) pq.push({x.second, x.first});

        string ans = "";
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            while (top.first--) ans += top.second;
        }
        
        return ans;
    }
};
