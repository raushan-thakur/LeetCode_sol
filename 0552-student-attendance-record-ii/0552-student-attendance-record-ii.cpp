class Solution {
public:
    int checkRecord(int n) {
        const int mod  = 1e9 + 7;
        long long o = 1;
        long long ol = 1;
        long long oll = 0;
        long long a = 1;
        long long al = 0;
        long long all = 0;
        for(int i=2;i<= n;i++){
            int newo = (o + ol + oll)%mod;
            int newol = o % mod;
            int newoll = ol % mod;
            int newa = (o + ol + oll + a + al + all) % mod;
            int newal = a % mod;
            int newall = al % mod;
            o = newo;
            ol = newol;
            oll = newoll;
            a = newa;
            al = newal;
            all = newall;

        }
        int ans = (o + ol + oll + a + al + all)%mod;

        return ans;
    }
};