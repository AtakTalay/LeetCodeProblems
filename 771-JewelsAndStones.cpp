//https://leetcode.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsSet;
        for(int i=0; i < jewels.length(); i++){
            jewelsSet.insert(jewels[i]);
        }
        int total = 0;
        for(int i=0; i < stones.length(); i++){
            if(jewelsSet.find(stones[i]) != jewelsSet.end()){
                total++;
            }
        }
        return total;
    }
};