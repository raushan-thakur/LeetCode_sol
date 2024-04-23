class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1001, 0);
        for (auto n: nums1) {
            if (cnt[n] < 1) cnt[n] += 1;
        }

        vector<int> res;
        for (auto n : nums2) {
            if (cnt[n] == 1) {
                cnt[n] += 1;
                res.push_back(n);
            }
        }
        return res;
    }
};