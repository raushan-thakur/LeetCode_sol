class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i = s.length()-1; i>=0 ;i --){
            if(i>=0 && s[i] == ' ') continue;
            int last = i;
             while(i>=0 && s[i] != ' ') i--;
            int ans = last - i;
            return ans;
        }
        return -1;
    }
};