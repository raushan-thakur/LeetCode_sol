class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
//         unordered_map<string,int> mp;
//         for(int i =0; i<s.length(); i++){
//             mp[s[i]]++;
//         }
//         for(int i =0; i<t.length(); i++){
//             mp[t[i]]--;
//         }
        
//         if(mp.empty()){
//             return true;
//         }
//         return false;
    }
};