//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        int rowCount = 0;
        int islands = 0;
        while(rowCount < m){
            while(rowCount < m && grid[rowCount][counter] != '1'){
                counter++;
                if(counter == n){
                    counter = 0;
                    rowCount++;
                }
            }
            if(rowCount == m){
                break;
            }
            changeOnes(grid, rowCount, counter);
            islands++;
        }
        return islands;
    }


    void changeOnes(vector<vector<char>>& grid, int r, int c){
        if(r >= grid.size() || c >= grid[0].size()){
            return;
        }
        grid[r][c] = '2';
        if(r > 0 && grid[r - 1][c] == '1'){
            grid[r - 1][c] = '2';
            changeOnes(grid, r - 1, c);
        }
        if(c > 0 && grid[r][c - 1] == '1'){
            grid[r][c - 1] = '2';
            changeOnes(grid, r, c - 1);
        }
        if(c < grid[0].size() - 1 && grid[r][c + 1] == '1'){
            grid[r][c + 1] = '2';
            changeOnes(grid, r, c + 1);
        }
        if(r < grid.size() - 1 && grid[r + 1][c] == '1'){
            grid[r + 1][c] = '2';
            changeOnes(grid, r + 1, c);
        }
    }
};