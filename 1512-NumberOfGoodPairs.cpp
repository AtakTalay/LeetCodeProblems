//https://leetcode.com/problems/number-of-good-pairs/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> elementPositions;
        map<int, int>::iterator itr;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            itr = elementPositions.find(nums[i]);
            if(itr != elementPositions.end()){
                total += itr->second;
                itr->second++;
            }
            else{
                cout << ":(" << endl;
                elementPositions.insert({nums[i], 1});
            }
        }
        return total;
    }
};