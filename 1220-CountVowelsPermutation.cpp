//https://leetcode.com/problems/count-vowels-permutation/
class Solution {
public:
    const int MODULO = (int)1e9 + 7;
    int countVowelPermutation(int n) {
        int total = 0;
        map<pair<char,int>,int> cache;
        total = (total + helper(n - 1, 'a', cache)) % MODULO;
        total = (total + helper(n - 1, 'e', cache)) % MODULO;
        total = (total + helper(n - 1, 'o', cache)) % MODULO;
        total = (total + helper(n - 1, 'i', cache)) % MODULO;
        total = (total + helper(n - 1, 'u', cache)) % MODULO;
        return total;

    }

    int helper(int n, char s, map<pair<char,int>,int>& cache){
        int total = 0;
        if(n == 0){
            return 1;
        }
        n--;
        if(cache.count({s,n})){
            total = cache[{s,n}];
        }
        else if(s == 'e'){
            total = (total + helper(n, 'a', cache)) % MODULO;
            total = (total + helper(n, 'i', cache)) % MODULO;
        }
        else if(s == 'i'){
            total = (total + helper(n, 'a', cache)) % MODULO;
            total = (total + helper(n, 'e', cache)) % MODULO;
            total = (total + helper(n, 'o', cache)) % MODULO;
            total = (total + helper(n, 'u', cache)) % MODULO;

        }
        else if(s == 'a'){
            total = (total + helper(n, 'e', cache)) % MODULO;
        }
        else if(s == 'o'){
            total = (total + helper(n, 'i', cache)) % MODULO;
            total = (total + helper(n, 'u', cache)) % MODULO;
        }
        else{
            total = (total + helper(n, 'a', cache)) % MODULO;
        }
        total = total % MODULO;
        cache.insert({{s,n},total});
        return total;
    }
};
