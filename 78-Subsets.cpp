//https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i = 0; i < (1 << nums.size()); i++){
            vector<int> comb;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    comb.push_back(nums[j]);
                }
            }
            result.push_back(comb);
        }
        return result;
    }
};