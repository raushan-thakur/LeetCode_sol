class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        sort(arr.begin(), arr.end());
        long long ans = 0;

        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] + arr[j] > upper) {
                --j;
            } else {
                ans += (j - i);
                ++i;
            }
        }

        i = 0;
        j = arr.size() - 1;
        while (i < j) {
            if (arr[i] + arr[j] > lower - 1) {
                --j;
            } else {
                ans -= (j - i);
                ++i;
            }
        }

        return ans;
    }
};