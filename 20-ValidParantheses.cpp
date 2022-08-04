//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if((stk.top() == '(' && s[i] != ')') || (stk.top() == '[' && s[i] != ']') || (stk.top() == '{' && s[i] != '}')){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};