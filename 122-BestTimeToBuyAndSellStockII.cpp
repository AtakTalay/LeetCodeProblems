//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buy = -1;
        for(int i = 1; i < n; i++){
            if(prices[i] < prices[i - 1] && buy != -1){
                profit += prices[i - 1] - buy;
                buy = -1;
            }
            if(prices[i] > prices[i - 1] && buy == -1){
                buy = prices[i - 1];
            }
        }
        if(buy != -1){
            profit += prices[n - 1] - buy;
        }
        return profit;
    }
};