//https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int srcColor = image[sr][sc];
        image[sr][sc] = newColor;
        return helper(image, sr, sc, newColor, srcColor);
    }
    vector<vector<int>> helper(vector<vector<int>>& image, int sr, int sc, int newColor, int srcColor){
        if(sr > 0 && srcColor == image[sr - 1][sc] && image[sr - 1][sc] != newColor){
            image[sr - 1][sc] = newColor;
            helper(image, sr - 1, sc, newColor, srcColor);
        }
        if(sc > 0 && srcColor == image[sr][sc - 1] && image[sr][sc - 1] != newColor){
            image[sr][sc - 1] = newColor;
            helper(image, sr, sc - 1, newColor, srcColor);
        }
        if(sc < image[0].size() - 1 && srcColor == image[sr][sc + 1] && image[sr][sc + 1] != newColor){
            image[sr][sc + 1] = newColor;
            helper(image, sr, sc + 1, newColor, srcColor);
        }
        if(sr < image.size() - 1 && srcColor == image[sr + 1][sc] && image[sr + 1][sc] != newColor){
            image[sr + 1][sc] = newColor;
            helper(image, sr + 1, sc, newColor, srcColor);
        }
        return image;
    }
};