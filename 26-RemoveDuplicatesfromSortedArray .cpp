//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int removedCount = 0;
        int count = 1;

        int size = nums.size();
        int changeIndex = 0;
        while(count < size){
            if(nums[count] == nums[changeIndex]){
                removedCount++;
            }
            else{
                nums[changeIndex + 1] = nums[count];
                changeIndex++;
            }
            count++;
        }
        return size - removedCount;
    }
};