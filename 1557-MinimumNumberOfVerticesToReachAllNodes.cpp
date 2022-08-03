//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool hasPredecessor[n];
        for(int i = 0; i < n; i++){
            hasPredecessor[i] = false;
        }
        for(int i = 0; i < edges.size(); i++){
            hasPredecessor[edges[i][1]] = true;
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(!hasPredecessor[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};