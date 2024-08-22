class Solution {
public:
    int findComplement(int n) {
        int num=floor(log2(n))+1;
        return ((1LL << num) -1) ^ n;
    }
};