class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0, z=0;
        for(auto&ch : s) ch=='0' ? ans+=z : z++;
        return ans;
    }
};