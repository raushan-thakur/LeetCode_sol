class Solution {
public:
    bool isSorted(const vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    int countSetBits(int num) {
        int bitCount = 0;
        for (int i = 31; i >= 0; i--) {
            if (((num >> i) & 1) == 1) bitCount++;
        }
        return bitCount;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> setBitsCount(101, 0);
        int currentIndex = 0, arrayLength = nums.size(), iterationCount = 0;

        for (int num : nums) {
            setBitsCount[currentIndex++] = countSetBits(num);
        }

        while (iterationCount < arrayLength) {
            for (int i = 1; i < arrayLength; i++) {
                if (setBitsCount[i] == setBitsCount[i - 1] && nums[i] < nums[i - 1]) {
                    int temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
            }

            if (isSorted(nums)) return true;
            iterationCount++;
        }

        return false;
    }


};