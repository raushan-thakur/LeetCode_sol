class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c] = freq.find(c) != freq.end() ? freq[c] + 1 : 1;
        }

        vector<char> sortedChars;
        for (const auto& pair : freq) {
            sortedChars.push_back(pair.first);
        }

        sort(sortedChars.begin(), sortedChars.end(), [&](char a, char b) {
            return freq[a] > freq[b];
        });

        int keyPresses = 0;
        int keyPosition = 1;
        int keyNumber = 2;

        for (char c : sortedChars) {
            keyPresses += freq[c] * keyPosition;
            if (keyNumber < 9) {
                keyNumber++;
            } else {
                keyNumber = 2;
                keyPosition++;
            }
        }

        return keyPresses;
    }
};