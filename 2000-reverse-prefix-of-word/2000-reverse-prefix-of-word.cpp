#include<bits/stdc++.h>
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        if(i != word.length())
            reverse(word.begin(), word.begin() + i+1);
        return word;
    }
};