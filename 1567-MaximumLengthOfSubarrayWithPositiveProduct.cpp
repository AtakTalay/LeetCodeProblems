//https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int minNeg = nums.size();
        int maxNeg = 0;
        bool isNeg = false;
        int maxLength = 0;
        int length = 0;
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                minNeg = min(minNeg, i);
                maxNeg = max(maxNeg, i);
                isNeg = !isNeg;
            }
            if(nums[i] == 0){
                if(!isNeg){
                    maxLength = max(maxLength, length);
                }
                else{
                    maxLength = max(maxLength, max(maxNeg - start, length + start- minNeg - 1));
                }
                length = -1;
                isNeg = false;
                minNeg = nums.size();
                start = i + 1;
                maxNeg = 0;
            }
            length++;
        }
        if(!isNeg){
            maxLength = max(maxLength, length);
        }
        else{
            maxLength = max(maxLength, max(maxNeg - start, length - minNeg + start - 1));
        }
        return maxLength;
    }
};