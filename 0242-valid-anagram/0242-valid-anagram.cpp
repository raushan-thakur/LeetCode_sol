class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp, mp2;
        for(int i =0; i<s.length(); i++){
            char curr1 = s[i];  
            char curr2 = t[i];  
            mp[curr1]++;
            mp2[curr2]++;
        }
        if(mp==mp2){
            return true;
        }
        return false;
    }
};