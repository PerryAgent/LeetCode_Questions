class Solution {
public:
//     string pb(vector<char> &s) {
//         for(int i=0; i< s.size(); i++){
            
//         }
//     }
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        for(int i =0; i<strs[0].length(); i++) {
            char c = strs[0][i];
            for(int j =1; j<strs.size(); j++) {
                if (i>=strs[j].length() || c != strs[j][i]){
                    return s;
                }
            }
            s.push_back(c);
        }
        // string st = pb(s);
        return s;
    }
};