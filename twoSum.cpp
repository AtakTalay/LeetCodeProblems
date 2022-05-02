//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> elements;
        map<int, int>::iterator itr;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            itr = elements.find(target - nums[i]);
            if(elements.size() != 0 && itr != elements.end()){
                result.push_back(itr->second);
                result.push_back(i);
                break;
            }
            elements.insert({nums[i], i});
        }
        return result;
    }
};