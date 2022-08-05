//https://leetcode.com/problems/split-a-string-in-balanced-strings/
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R'){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                result++;
            }
        }
        return result;
    }
};