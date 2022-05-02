//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustCount[n];
        bool trustsAnyOne[n];
        for(int i = 0; i < n; i++){
            trustCount[i] = 0;
            trustsAnyOne[i] = false;
        }
        for(int i = 0; i < trust.size(); i++){
            trustCount[trust[i][1] - 1]++;
            trustsAnyOne[trust[i][0] - 1] = true;
        }
        int result = -1;
        for(int i = 0; i < n; i++){
            if(trustCount[i] == n - 1 && !trustsAnyOne[i]){
                if(result != -1){
                    return -1;
                }
                result = i + 1;
            }
        }
        return result;
    }
};