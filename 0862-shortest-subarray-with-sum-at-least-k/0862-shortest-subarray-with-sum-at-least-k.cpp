class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        deque<int> q;
        int res = INT_MAX;
        for (int i = 0; i < n+1; ++i) {
            while (!q.empty() && sums[i] - sums[q.back()] <= 0) {
                q.pop_back();
            }
            while (!q.empty() && sums[i] - sums[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return res != INT_MAX ? res : -1;
    }
};