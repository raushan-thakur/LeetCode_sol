class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int arrival = times[t][0];
        sort(times.begin(), times.end());
        set<int> s;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int newSeat = 0;
        int ans;
        for(int i=0; i<times.size(); i++) {
            int seat=-1;
            while(!pq.empty() && pq.top().first <= times[i][0]) {
                seat = pq.top().second;
                pq.pop();
                s.insert(seat);
            }
            if(s.size() > 0) {
                seat = *(s.begin());
                s.erase(seat);
            }
            else {
                seat = newSeat++;
            }
            pq.push({times[i][1], seat});
            if(times[i][0] == arrival) {
                ans = seat;
                break;
            }
        }
        return ans;
    }
};