//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        int count = 0;
        while(count < nums.size() && count <= maxPos){
            maxPos = max(maxPos, count + nums[count]);
            count++;
        }
        if(count == nums.size()){
            return true;
        }
        return false;
    }
};