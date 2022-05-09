//https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int counter = 0;
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        int rowCount = 0;
        int maxArea = 0;
        while(rowCount < m){
            int area = 0;
            while(rowCount < m && grid[rowCount][counter] != 1){
                counter++;
                if(counter == n){
                    counter = 0;
                    rowCount++;
                }
            }
            if(rowCount == m){
                break;
            }
            changeOnes(grid, rowCount, counter, area);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }


    void changeOnes(vector<vector<int>>& grid, int r, int c, int& area){
        if(r >= grid.size() || c >= grid[0].size()){
            return;
        }
        grid[r][c] = 2;
        area++;
        if(r > 0 && grid[r - 1][c] == 1){
            grid[r - 1][c] = 2;
            changeOnes(grid, r - 1, c, area);
        }
        if(c > 0 && grid[r][c - 1] == 1){
            grid[r][c - 1] = 2;
            changeOnes(grid, r, c - 1, area);
        }
        if(c < grid[0].size() - 1 && grid[r][c + 1] == 1){
            grid[r][c + 1] = 2;
            changeOnes(grid, r, c + 1, area);
        }
        if(r < grid.size() - 1 && grid[r + 1][c] == 1){
            grid[r + 1][c] = 2;
            changeOnes(grid, r + 1, c, area);
        }
    }
};