//https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int matSize = mat.size() * mat[0].size();
        if(r * c != matSize){
            return mat;
        }
        vector<vector<int>> result;
        vector<int> a;        
        int colCount = 1;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                a.push_back(mat[i][j]);
                if(colCount == c){
                    colCount = 1;
                    result.push_back(a);
                    a.clear();
                }
                else{
                    colCount++;
                }
            }
        }
        return result;
    }
};