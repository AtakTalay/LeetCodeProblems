//https://leetcode.com/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        while(n != 1){
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if(nums.find(n) != nums.end()){
                return false;
            }
            nums.insert(n);
        }
        return true;
    }
};