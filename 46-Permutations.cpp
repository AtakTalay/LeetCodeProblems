//https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<bool> chosen(nums.size(), false);
        vector<vector<int>> permutations;
        genPerm(nums, chosen, perm, permutations);
        return permutations;
    }
    
    void genPerm(vector<int>&nums, vector<bool> chosen, vector<int> perm, vector<vector<int>>& permutations){
        if(perm.size() == nums.size()){
            permutations.push_back(perm);
        }
        for(int i = 0; i < nums.size(); i++){
            if(chosen[i]){
                continue;
            }
            chosen[i] = true;
            perm.push_back(nums[i]);
            genPerm(nums, chosen, perm, permutations);
            chosen[i] = false;
            perm.pop_back();
        }
    }
};