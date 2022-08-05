//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int prevMax = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prevMax = max(prevMax + nums[i], nums[i]);
            maxSum = max(maxSum, prevMax);
        }
        return maxSum;
    }
};