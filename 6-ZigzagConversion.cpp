//https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string result = "";
        for(int i = 0; i < s.length(); i += 2 * numRows - 2){
            result += s[i];
        }
        for(int i = 1; i < numRows - 1; i++){
            int count = i;
            while(count < s.length()){
                result += s[count];
                count += 2 * numRows - 2 - 2 * i;
                if(count < s.length()){
                    result += s[count];
                    count += 2 * i;
                }
            }
        }
        if(numRows > 1){
            for(int i = numRows - 1; i < s.length(); i += 2 * numRows - 2){
                result += s[i];
            }
        }
        return result;
    }
};