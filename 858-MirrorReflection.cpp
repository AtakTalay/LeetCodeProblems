//https://leetcode.com/problems/mirror-reflection/
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = 1;
        int y = 0;
        int count = q;
        while(count % p != 0){
            x++;
            count += q;
        }

        y = count / p;
        if(x % 2 == 1 && y % 2 == 0){
            return 0;
        }
        else if(x % 2 == 1 && y % 2 == 1){
            return 1;
        }
        else return 2;
    }
};