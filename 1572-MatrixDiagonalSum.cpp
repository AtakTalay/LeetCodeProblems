//https://leetcode.com/problems/matrix-diagonal-sum/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int total = 0;
        for(int i = 0; i < mat.size(); i++){
            total += mat[i][i];
        }
        for(int i = 0; i < mat.size(); i++){
            total += mat[mat.size() - 1 - i][i];
        }
        if(mat.size() % 2 == 1){
            total -= mat[mat.size() / 2][mat.size() / 2];
        }
        return total;
    }
};