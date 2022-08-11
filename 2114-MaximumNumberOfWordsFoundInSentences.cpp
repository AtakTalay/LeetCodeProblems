//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWord = 0;
        for(string s: sentences){
            int word = 0;
            for(char c: s){
                if(c == ' '){
                    word++;
                }
            }
            maxWord = max(maxWord, word);
        }
        return maxWord + 1;
    }
};