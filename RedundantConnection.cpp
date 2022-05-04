//https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    bool isPath(int n, vector<vector<int>>& edges, int start, int destination){
        queue<int> vertices;
        vertices.push(start);
        bool visited[n];
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        vector<int> adjacent[n];
        for(int i=0;i<edges.size();i++){
            adjacent[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adjacent[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        visited[start] = true;
        while (!vertices.empty()) {
            int v = vertices.front();
            vertices.pop();
            for(int i = 0; i < adjacent[v].size(); i++){
                if(!visited[adjacent[v][i]]){
                    visited[adjacent[v][i]] = true;
                    vertices.push(adjacent[v][i]);
                }
            }
        }
        return visited[destination];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> newEdges;
        int n = edges.size();
        vector<int> result;
        for(int i = 0; i < n; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            if(isPath(n, newEdges, x - 1, y - 1)){
                result.clear();
                result.push_back(x);
                result.push_back(y);
            }
            newEdges.push_back(edges[i]);
        }
        return result;
    }
};