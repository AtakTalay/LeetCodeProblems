//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> first;
        first.push_back(1);
        result.push_back(first);
        for(int i = 1; i < numRows; i++){
            vector<int> a;
            a.push_back(1);
            for(int j = 1; j < i; j++){
                a.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            a.push_back(1);
            result.push_back(a);
        }
        return result;
    }
};