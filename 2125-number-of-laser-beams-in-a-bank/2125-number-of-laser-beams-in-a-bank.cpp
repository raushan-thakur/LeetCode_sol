class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for (int i = 0; i < bank.size(); i++) {
            int curr = count(bank[i].begin(), bank[i].end(), '1');
            if (curr == 0) continue;
            ans += prev * curr;
            prev = curr;
        }
        return ans;
    }
};