class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 0;
        int last = 0;
        
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == ' ' || i==sentence.size()-1){
                ans++;
                string s = sentence.substr(last,i);
                int cnt=0;
                for(int j=0; j<searchWord.size() && sentence.size(); j++){
                    
                    if(searchWord[j] != s[j])break;
                    cnt++;
                }
                if(cnt == searchWord.size()) return ans;
                last = i+1;
            }
        }
        return -1;
    }
};