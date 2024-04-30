class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        int x = 0;
        long long result = 0;

        for(char &ch : word){  
            int shift = ch - 'a';
            x ^= (1 << shift);

            result += mp[x]; 

            for(char ch1='a'; ch1<='j'; ch1++){ 
                shift = ch1 - 'a';

                long long c = (x ^ (1 << shift));

                result += mp[c];  
            }
            mp[x] ++ ;
        }
        return result;
    }
};