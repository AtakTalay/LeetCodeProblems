//https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        map<pair<int,int>, int> cache;
        return helper(amount, coins, coins.size() - 1, cache);
    }
    
    int helper(int amount, vector<int> coins, int lastIndex, map<pair<int,int>, int>& cache){
        if(amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(cache.find({amount, lastIndex}) != cache.end()){
            return cache[{amount,lastIndex}];
        }
        int total = 0;
        for(int i = 0; i <= lastIndex; i++){
            total += helper(amount - coins[i], coins, i, cache);
        }
        cache.insert({{amount, lastIndex}, total});
        return total;
    }
};