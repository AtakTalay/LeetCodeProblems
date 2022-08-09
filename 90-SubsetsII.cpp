//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
        vector<vector<int>> actualResult;
        actualResult.push_back(result[0]);
        for(int i = 0; i < result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }
        sort(result.begin(), result.end());
        for(int i = 1; i < result.size(); i++){
            if(result[i] != result[i - 1]){
                actualResult.push_back(result[i]);
            }
        }
        return actualResult;
    }
};