//https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int maxSat = 0;
        sort(satisfaction.begin(), satisfaction.end());
        int total = 0;
        for(int x: satisfaction){
            total += x;
        }
        int count = 0;
        while(count < satisfaction.size() && total < 0){
            total -= satisfaction[count];
            count++;
        }
        cout << count;
        int multiplier = 1;
        for(int i = count; i < satisfaction.size(); i++){
            maxSat += satisfaction[i] * multiplier;
            multiplier++;
        }
        return maxSat;
    }
};