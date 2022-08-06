//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs[0].length(); i++){
            string p = s;
            p += strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(strs[j].find(p) != 0){
                    return s;
                }
            }
            s = p;
        }
        return s;
    }
};