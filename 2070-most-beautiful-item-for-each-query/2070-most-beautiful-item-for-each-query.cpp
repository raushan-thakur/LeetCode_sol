class Solution {
private:
    int lastOccurence(vector<vector<int>>& items, int val) {
        int s = 0;
        int e = items.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (items[mid][0] <= val) {
                ans = mid;
                s = mid + 1;
            } else
                e = mid - 1;
        }
        return ans;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        int n = queries.size();
        vector<int> ans(n, 0);
        int index = 0;

        sort(items.begin(), items.end());
        vector<int> vec;

        int maxi = items[0][1];
        vec.push_back(maxi);

        for (int i = 1; i < items.size(); i++) {
            maxi = max(maxi, items[i][1]);
            vec.push_back(maxi);
        }

        for (int i = 0; i < n; i++) {
            int maxi = 0;

            int val = queries[i];
            int j = lastOccurence(items, val);

            if (j == -1)
                ans[index] = 0;

            else {
                maxi = vec[j];
                ans[index] = maxi;
            }
            index++;
        }
        return ans;
    }
};