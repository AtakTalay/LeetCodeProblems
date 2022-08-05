//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int n) {
        vector<int> results(31, 0);
        return fibHelper(n, results);
    }
    
    int fibHelper(int n, vector<int>& results){
        if(n < 2){
            return n;
        }
        if(results[n] != 0){
            return results[n];
        }
        results[n] = fibHelper(n - 1, results) + fibHelper(n - 2, results);
        return results[n];
    }
};