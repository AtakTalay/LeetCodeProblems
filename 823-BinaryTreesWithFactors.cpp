//https://leetcode.com/problems/binary-trees-with-factors/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MODULO = (int)1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> nums;
        for(int i = 0; i < arr.size(); i++){
            nums.insert({arr[i], i});
        }
        
        vector<long> dp(arr.size(), 1);
        for(int i = 1; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                int div = arr[i] / arr[j];
                if(arr[i] % arr[j] == 0 && nums.count(div)){
                    dp[i] = (dp[i] + dp[j] * dp[nums[div]]) % MODULO;
                }
            }
        }
        long total = 0;
        for(long l : dp){
            total = (total + l) % MODULO;
        }
        return total;
    
    }
};