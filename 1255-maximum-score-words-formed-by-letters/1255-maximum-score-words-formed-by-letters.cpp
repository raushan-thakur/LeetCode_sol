class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> v = vector<int>(26, 0);
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, v, 0);
        return maxScore;
    }

private:
    int maxScore;
    vector<int> freq;

    bool isValidWord(vector<int>& v) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < v[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score, vector<int>& v, int totalScore) {
        if (w == -1) {
            maxScore = max(maxScore, totalScore);
            return;
        }
        check(w - 1, words, score, v, totalScore);
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            v[c]++;
            totalScore += score[c];
        }

        if (isValidWord(v)) {
            check(w - 1, words, score, v, totalScore);
        }
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            v[c]--;
            totalScore -= score[c];
        }
    }
};