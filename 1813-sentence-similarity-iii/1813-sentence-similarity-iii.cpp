class Solution {
public:
    vector<string> f(string str){
        vector<string> res;
        string w = "";
        for(auto c:str){
            if(c==' '){
                if(!w.empty()){
                    res.push_back(w);
                    w="";
                }
            }
            else{
                w+=c;
            }
        }
        if(!w.empty()){
            res.push_back(w);
        }
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1  = f(sentence1);
        vector<string> words2  = f(sentence2);
        if(words1.size()<words2.size()){
            swap(words1,words2);
        }

        int start = 0, end = 0;
        int n = words1.size() , m = words2.size();
        while(start<m && words1[start]==words2[start]){
            start++;
        }

        while(end<m && words1[n - end - 1 ]==words2[m - end - 1]){
            end++;
        }

        return start + end >= m;

        
    }
};