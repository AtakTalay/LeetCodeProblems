//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left;
        vector<int> right;
        int hMax = 0;
        for(int i = 0; i < n; i++){
            hMax = max(height[i], hMax);
            left.push_back(hMax);
        }
        hMax = 0;
        for(int i = n-1; i > -1; i--){
            hMax = max(height[i], hMax);
            right.push_back(hMax);
        }
        int total = 0;
        for(int i = 0; i < n; i++){
            total += min(left[i], right[n - 1 - i]) - height[i];
        }
        return total;
    }
};