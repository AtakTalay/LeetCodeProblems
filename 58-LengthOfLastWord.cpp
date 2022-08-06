//https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = s.length() - 1;
        bool charFound = false;
        int spaceCount = 0;
        while(count >= 0){
            if(s[count] == ' ' && charFound){
                return s.length() - 1 - count - spaceCount;
            }
            else if(s[count] == ' ' && !charFound){
                spaceCount++;
            }
            if(s[count] != ' '){
                charFound = true;
            }
            count--;
        }
        return s.length() - spaceCount;
    }
};