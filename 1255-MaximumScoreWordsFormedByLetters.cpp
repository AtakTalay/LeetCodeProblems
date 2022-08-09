//https://leetcode.com/problems/maximum-score-words-formed-by-letters/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCount(26, 0);
        for(char c : letters){
            letterCount[(int) c - 'a']++;
        } 
        int maxScore = 0;
        for(int i = 0; i < (1 << words.size()); i++){
            int curScore = 0;
            vector<int> a = letterCount;
            for(int j = 0; j < words.size(); j++){
                if( i & (1 << j)){
                    int wordScore = 0;
                    string word = words[j];
                    int lastIndex = word.length();
                    for(int k = 0; k < word.length(); k++){
                        int LetterIndex = (int) word[k] - 'a';
                        if(a[LetterIndex] > 0){
                            wordScore += score[LetterIndex];
                            a[(int) word[k] - 'a']--;
                        }
                        else{
                            lastIndex = k;
                            break;
                        }
                    }
                    if(lastIndex != word.length()){
                        for(int k = 0; k < lastIndex; k++){
                            int LetterIndex = (int)word[k] - 'a';
                            a[LetterIndex]++;
                        }
                    }
                    else{
                        curScore += wordScore;
                    }
                }
            }
            maxScore = max(maxScore, curScore);
        }
        return maxScore;
    }
};