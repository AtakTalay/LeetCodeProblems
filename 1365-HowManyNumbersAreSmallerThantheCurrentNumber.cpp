//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> old = nums;
        vector<int>::iterator it;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < old.size(); i++){
            it = find(nums.begin(), nums.end(), old[i]);
            old[i] = it - nums.begin();
        }
        return old;
    }
};