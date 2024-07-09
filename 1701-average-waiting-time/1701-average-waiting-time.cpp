class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long time = 0, sum = 0;
        for(auto &c : customers) {
            time = max(time, (long)c[0]) + c[1]; 
            sum += (time - c[0]);
        }
        return (double) sum / customers.size();
    }
};