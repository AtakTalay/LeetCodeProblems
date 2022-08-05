//https://leetcode.com/problems/best-sightseeing-pair/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxRes = 0;
        int maxFirst = values[0];
        for(int i = 1; i < values.size(); i++){
            maxRes = max(maxRes, maxFirst + values[i] - i);
            maxFirst = max(maxFirst, values[i] + i);
        }
        return maxRes;
    }
};