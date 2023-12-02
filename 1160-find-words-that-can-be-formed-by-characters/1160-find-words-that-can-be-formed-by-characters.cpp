class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        map<char, int> mp;
        for(int i = 0 ; i< chars.length(); i++){
            mp[chars[i]]++;
        }
        map<char, int> temp = mp;
        int ans = 0;
        for(int i =0; i<words.size(); i++){
            bool check = true;
            for(int j = 0 ; j<words[i].length(); j++){
                char ch = words[i][j];
                if(temp[ch]>0){
                    temp[ch]--;
                }else{
                    check = false;
                    break;
                }
            }
            
            if(check){
                ans+=words[i].length();
            }
            temp = mp;
        }
        return ans;
    }
};