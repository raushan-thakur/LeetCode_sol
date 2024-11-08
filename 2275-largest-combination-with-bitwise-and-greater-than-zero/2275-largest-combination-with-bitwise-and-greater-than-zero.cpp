class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(25,0);
        for(auto it: candidates){
            for(int i=0; i<25; i++){
                if((1<<i)&it)
                    freq[i]++;
            }
        }
        return *max_element(freq.begin(), freq.end());
    }
};