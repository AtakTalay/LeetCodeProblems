//https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool visited[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        queue<int> v;
        int next = 0;
        int provinceCount = 0;
        while(count < n ){
            while(visited[next]){
                next++;
            }
            v.push(next);
            visited[next] = true;
            count++;
            while(!v.empty()){
                int u = v.front();
                v.pop();
                for(int i = 0; i < n ; i++){
                    if(isConnected[u][i] == 1 && !visited[i]){
                        visited[i] = true;
                        v.push(i);
                        count++;
                    }
                }
            }
            provinceCount++;
        }
        return provinceCount;
    }
};