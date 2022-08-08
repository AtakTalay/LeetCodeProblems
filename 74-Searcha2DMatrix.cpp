//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        if(target > matrix[matrix.size() - 1][0]){
            row = matrix.size() - 1;
        }
        else if(target < matrix[0][0]){
            return false;
        }
        else if(target == matrix[0][0]){
            return true;
        }
        else{
            while(target > matrix[row][0]){
                row++;
            }
            if(target == matrix[row][0]){
                return true;
            }
            row--;
        }

        cout << row << " ";

        return helper(matrix, row, target, 0, matrix[0].size() - 1);
    }
    
    bool helper(vector<vector<int>>& matrix, int row, int target, int low, int high){
        cout << "low: " << low << " high: " << high << endl;
        if(low <= high){
            int mid = (low + high) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(low == high){
                return false;
            }
            else if(matrix[row][mid] < target){
                return helper(matrix, row, target, mid + 1, high);
            }
            else{
                return helper(matrix, row, target, low, mid);
            }
        }
        return false;
    }
};