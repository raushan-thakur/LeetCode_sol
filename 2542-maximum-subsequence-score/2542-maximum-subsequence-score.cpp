class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long currSum = 0;

        for (int i = n - k; i < n; i++) {
            pq.push(v[i].second);
            currSum += v[i].second;
        }

        long long ans = currSum * v[n - k].first;

        for (int i = n - k - 1; i >= 0; i--) {
            pq.push(v[i].second);
            currSum += v[i].second;

            currSum -= pq.top();
            pq.pop();

            ans = max(ans, currSum * v[i].first);
        }

        return ans;
    }
};
