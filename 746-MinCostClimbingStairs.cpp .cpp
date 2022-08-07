//https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> a;
        a.push_back(cost[0]);
        a.push_back(cost[1]);
        for(int i = 2; i < cost.size(); i++){
            a.push_back(min(a[i - 1], a[i - 2]) + cost[i]);
        }
        return min(a[cost.size()- 1], a[cost.size() - 2])  ;
    }
};