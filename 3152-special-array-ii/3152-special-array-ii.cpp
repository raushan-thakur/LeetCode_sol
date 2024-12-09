class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i]%2 == nums[i-1]%2) {
                res.push_back(i); 
            } else {
                res.push_back(res.back());            }
        }

        vector<bool> ans;

        for (auto q : queries) {
            int i = q[1];
            int req = q[0];

            ans.push_back(res[i] <= req);
        }

        return ans;
    }
};