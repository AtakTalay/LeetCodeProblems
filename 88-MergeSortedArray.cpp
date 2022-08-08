//https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a;
        int countM = 0;
        int countN = 0;
        while(countM < m && countN < n){
            if(nums1[countM] < nums2[countN]){
                a.push_back(nums1[countM]);
                countM++;
            }
            else{
                a.push_back(nums2[countN]); 
                countN++;
            }
        }
        while(countM < m){
            a.push_back(nums1[countM]);
            countM++;
        }
        while(countN < n){
            a.push_back(nums2[countN]);
            countN++;
        }
        nums1 = a;
    }
};