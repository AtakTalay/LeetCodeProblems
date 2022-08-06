//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroIndex = -1;
        int count = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] != 0 && firstZeroIndex != i && firstZeroIndex != -1){
                nums[firstZeroIndex] = nums[i];
                nums[i] = 0;
                firstZeroIndex++;
            }
            if(nums[i] == 0 && firstZeroIndex == -1){
                firstZeroIndex = i;
            }
            count++;
        }
    }
};