//https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(auto x : operations){
            if(x == "--X" || x == "X--"){
                count--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};