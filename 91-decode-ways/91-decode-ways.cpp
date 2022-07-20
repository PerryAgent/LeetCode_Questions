class Solution {
public:
    int tc;
    int count(string& s, int i, map<int, int>& dp) {
        if(i>=s.length()){
            return 1;
        }
        
        if(dp.find(i)!=dp.end()) return dp[i];
        
        if(s[i]=='0')
            return dp[i] = 0;
        int a1 = count(s, i+1, dp);
        int a2 = 0;
        if (i<s.length()-1 && s.substr(i,2) <= "26")
            a2 = count(s, i+2, dp);
        return dp[i] = a1+a2;
    }
    int numDecodings(string s) {
        map<int, int>dp;
        int ans = count(s, 0, dp);
        return ans;
    }
};