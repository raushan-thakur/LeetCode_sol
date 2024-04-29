class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        
        int count = 0;
        for (int i : nums) {
            ans ^= i;
        }
        int xorResult = ans ^ k;

        while (xorResult) {
            count += xorResult & 1;
            xorResult >>= 1;
        }
        return count;
    }
};