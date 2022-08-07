//https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isBroken = false;
        for(int i = digits.size() - 1; i > -1; i--){
            if(digits[i] != 9){
                digits[i] = digits[i] + 1;
                isBroken = true;
                break;
            }
            else{
                digits[i] = 0;
            }
        }
        if(!isBroken){
            vector<int> a;
            a.push_back(1);
            for(auto x : digits){
                a.push_back(x);
            }
            return a;
        }
        return digits;
    }
};