//https://leetcode.com/problems/climbing-stairs/    
class Solution {
public:
    int climbStairs(int n) {
        vector<int> results(46, 0);
        return fibHelper(n, results);
    }
    
    int fibHelper(int n, vector<int>& results){
        if(n < 2){
            return n;
        }
        if(n == 2){
            return 2;
        }
        if(results[n] != 0){
            return results[n];
        }
        results[n] = fibHelper(n - 1, results) + fibHelper(n - 2, results);
        return results[n];
    }
};