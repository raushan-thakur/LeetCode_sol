class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int n = arr.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i] + 1;
            if (((i + 1) * (i + 2)) / 2 == sum) ans++;
        }

        return ans;
    }
};