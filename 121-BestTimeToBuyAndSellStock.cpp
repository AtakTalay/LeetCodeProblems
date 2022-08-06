//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuy = prices[0];
        for(int p : prices){
            if(p < minBuy){
                minBuy = p;
            }
            else{
                profit = max(profit, p - minBuy);
            }
        }
        return profit;
    }
};