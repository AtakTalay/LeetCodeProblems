//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size());
    }
    
    int helper(vector<int>&nums, int target, int low, int high){
        if(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                return helper(nums, target, mid + 1, high);
            }
            else{
                return helper(nums, target, low, mid);
            }
        }
        return low;
    }
};