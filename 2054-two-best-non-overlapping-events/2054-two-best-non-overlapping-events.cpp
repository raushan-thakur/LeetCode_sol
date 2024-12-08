class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int n = events.size();
        vector<int> maxValue(n, 0);
        maxValue[0] = events[0][2];
        for (int i = 1; i < n; i++) {
            maxValue[i] = max(maxValue[i - 1], events[i][2]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int currentValue = events[i][2];
            int left = -1, right = i - 1;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (events[mid][1] < events[i][0]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            if (left != -1) {
                currentValue += maxValue[left];
            }

            result = max(result, currentValue);
        }

        return result;
    }
};