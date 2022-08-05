//https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int minGrid[grid.size()][grid[0].size()];
        minGrid[0][0] = grid[0][0];
        for(int i = 1; i < grid[0].size(); i++){
            minGrid[0][i] = minGrid[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < grid.size(); i++){
            minGrid[i][0] = minGrid[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                minGrid[i][j] = min(minGrid[i - 1][j], minGrid[i][j-1]) + grid[i][j];
            }
        }
        return minGrid[grid.size() - 1][grid[0].size() - 1];
    }
};