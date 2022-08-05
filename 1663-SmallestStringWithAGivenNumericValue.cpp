//https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
        int pos = 0;
        while((n - 1) * 26 >= k){
            s += 'a';
            n--;
            k--;
            pos++;
        }
        while(k > 26){
            s += 'z';
            k -= 26;
        }
        char midChar = (char)('a' + (k - 1));
        s.insert(pos, 1, midChar);
        return s;
    }
};