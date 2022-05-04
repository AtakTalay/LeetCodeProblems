//https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = rooms.size();
        queue<int> vertices;
        vertices.push(0);
        bool visited[count];
        for(int i = 0; i < count; i++){
            visited[i] = false;
        }
        visited[0] = true;
        while (!vertices.empty()) {
            int v = vertices.front();
            vertices.pop();
            for(int i = 0; i < rooms[v].size(); i++){
                if(!visited[rooms[v][i]]){
                    visited[rooms[v][i]] = true;
                    count--;
                    vertices.push(rooms[v][i]);
                }
            }
        }
        return count == 1;
    }
};