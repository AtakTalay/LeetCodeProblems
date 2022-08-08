//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        bool isErrorAppeared = false;
        int maxMisPlaced = 0;
        int minIndex = nums.size();
        int largeIndex = nums.size() - 1;
        int minNum = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1] && !isErrorAppeared){
                minIndex = i - 1;
                maxMisPlaced = nums[i - 1];
                minNum = nums[i];
                isErrorAppeared = true;
            }
            if(isErrorAppeared && nums[i] < nums[i - 1]){
                maxMisPlaced = max(maxMisPlaced, nums[i - 1]);
                minNum = min(minNum, nums[i]);
                largeIndex = i;
            }
            if(nums[i] < maxMisPlaced){
                largeIndex = i;
            }
        }
        for(int i = 0; i < minIndex; i++){
            if(nums[i] > minNum){
                minIndex = i;
                break;
            }
        }
        return largeIndex - minIndex + 1;
    }
};