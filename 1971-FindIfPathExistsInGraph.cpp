//https://leetcode.com/problems/find-if-path-exists-in-graph/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> vertices;
        vertices.push(source);
        bool visited[n];
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        vector<int> adjacent[n];
        for(int i=0;i<edges.size();i++){
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }

        visited[source] = true;
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
};