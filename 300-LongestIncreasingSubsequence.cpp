//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> a(nums.size(), 1);
        int maxSub = 1;
        for(int i = 1; i < nums.size(); i++){
            int maxSmaller = 0;
            for(int j = i - 1; j > -1; j--){
                if(nums[j] < nums[i]){
                    maxSmaller = max(maxSmaller, a[j]);
                }
            }
            a[i] = maxSmaller + 1;
            maxSub = max(maxSub, a[i]);
        }
        for(int i : a){
            cout << i << " ";
        }
        return maxSub;
    }
};