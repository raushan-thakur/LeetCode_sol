class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int sum=a^b;
            b=(uint32_t)(a&b)<<1;
            a=sum;
            
        }
        return a;
    }
};