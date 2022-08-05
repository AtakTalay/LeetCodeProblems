//https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    int tribonacci(int n) {
        vector<int> results(38, 0);
        return trifibHelper(n, results);
    }
    
    int trifibHelper(int n, vector<int>& results){
        if(n < 2){
            return n;
        }
        if(n == 2){
            return 1;
        }
        if(results[n] != 0){
            return results[n];
        }
        results[n] = trifibHelper(n - 1, results) + trifibHelper(n - 2, results) + trifibHelper(n - 3, results);
        return results[n];
    }
};