//https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int,int> cache;
        return combinationSum4Helper(nums, target, cache);
    }
    int combinationSum4Helper(vector<int>& nums, int target, map<int,int>& cache){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(cache.find(target) != cache.end()){
            return cache.find(target)->second;
        }
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i]){
                total += combinationSum4Helper(nums, target - nums[i], cache);
            }
        }
        cache.insert({target, total});
        return total;
    }
};