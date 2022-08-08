//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int lastMax = intervals[0][1];
        vector<vector<int>> result;
        vector<int> a;
        a.push_back(intervals[0][0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= lastMax){
                lastMax = max(intervals[i][1], lastMax);
            }
            else{
                a.push_back(lastMax);
                result.push_back(a);
                a.clear();
                a.push_back(intervals[i][0]);
                lastMax = intervals[i][1];
            }
        }
        if(a.size() != 0){
            a.push_back(lastMax);
            result.push_back(a);
        }
        return result;
    }
};