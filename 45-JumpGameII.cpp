//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> d(nums.size(), 100000);
        d[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            int count = 1;
            while(count <= nums[i] && i + count < nums.size()){
                d[i + count] = min(d[i + count], d[i] + 1);
                count++;
            }
        }
        return d[nums.size() - 1];
    }
};  