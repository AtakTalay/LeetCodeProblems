//https://leetcode.com/problems/delete-and-earn/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> a(10001, 0);
        for(int x : nums){
            a[x] += x;
        }
        int maxPoint = 0;
    }
};