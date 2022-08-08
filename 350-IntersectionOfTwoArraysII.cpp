//https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> firstArray;
        vector<int> result;
        for(int x : nums1){
            firstArray[x]++;
        }
        for(int y : nums2){
            if(firstArray.find(y) != firstArray.end() && firstArray[y] > 0){
                firstArray[y]--;
                result.push_back(y);
            }
        }
        return result;
    }   
};