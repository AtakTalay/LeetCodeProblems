//https://leetcode.com/problems/defanging-an-ip-address/
class Solution {
public:
    string defangIPaddr(string address) {
        int count = 0;
        string s = "";
        while(count < address.length()){
            if(address[count] == '.'){
                s += "[.]";
            }
            else{
                s += address[count];
            }
            count++;
        }
        return s;
    }
};