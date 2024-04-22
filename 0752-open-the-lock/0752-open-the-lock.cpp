class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        
        if (visited.count("0000")) return -1;
        
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();
                
                if (current == target) return level;
                
                for (const string& next : neighbors(current)) {
                    if (!visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            ++level;
        }
        
        return -1;
    }
    
private:
    vector<string> neighbors(const string& lock) {
        vector<string> result;
        for (int i = 0; i < 4; ++i) {
            string up = lock, down = lock;
            up[i] = (up[i] == '9') ? '0' : up[i] + 1;
            down[i] = (down[i] == '0') ? '9' : down[i] - 1;
            result.push_back(up);
            result.push_back(down);
        }
        return result;
    }
};
