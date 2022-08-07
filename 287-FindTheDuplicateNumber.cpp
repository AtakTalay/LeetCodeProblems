//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for(int x : nums){
            if(a.count(x)){
                return x;
            }
            a.insert(x);
        }
        return 0;
    }
};