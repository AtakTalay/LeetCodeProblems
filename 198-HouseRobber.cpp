//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() >= 3){
            nums[2] = nums[2] + nums[0];
        }
        for(int i = 3; i < nums.size();i++){
            nums[i] = nums[i] + max(nums[i - 2], nums[i - 3]);
        }
        for(int i : nums){
            cout << i << endl;
        }
        return max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};