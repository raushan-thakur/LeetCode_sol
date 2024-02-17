class Node {
public:
    int h;
};

bool operator< (const Node &a, const Node &b) {
    return a.h > b.h;
}

class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = (int)h.size();
        int result = 0;
        int b = 0;
        priority_queue<Node> q;
        for (int i = 1; i < n; ++i) {
            int diff = h[i] - h[i - 1];
            if (diff <= 0) {
                result = i;
                continue;
            }
            q.push({diff});
            if ((int)q.size() > ladders) {
                b += q.top().h;
                q.pop();
                if (b > bricks) break;
            }
            result = i;
        }
        return result;
    }
};