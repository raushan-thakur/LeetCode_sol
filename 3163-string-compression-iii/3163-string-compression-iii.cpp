class Solution {
public:
    string compressedString(string word) {
        string result;
        int count = 1;
        int n = word.length();
        
        for (int i = 1; i < n; ++i) {
            if (count == 9 || word[i] != word[i - 1]) {
                result += std::to_string(count) + word[i - 1];
                count = 1;
            } else {
                ++count;
            }
        }
        
        result += to_string(count) + word[n - 1];
        return result;
    }
};