//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs(x));
        string result = "";
        for(int i = s.length() - 1; i > -1; i--){
            result += s[i];
        }
        if(x < 0){
            result = "-" + result;
        }
        long res = stol(result);
        if(res > 2147483647 || res < -2147483648){
            return 0;
        }
        return res;
    }
};