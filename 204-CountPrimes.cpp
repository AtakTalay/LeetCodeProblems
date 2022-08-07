//https://leetcode.com/problems/count-primes/
class Solution {
public:

    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        vector<bool> notPrimes(n, false);
        int count = 1;
        for(int i = 3; i < n; i+= 2){
            if(!notPrimes[i]){
                count++;
                for(long j = (long)i * i ; j < n; j += i){
                    notPrimes[j] = true;
                }
            }

        }



        return count;
    }
};