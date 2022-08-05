//https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seennums;
        for(int num : nums){
            if(seennums.find(num) != seennums.end()){
                return true;
            }
            seennums.insert(num);
        }
        return false;
    }
};