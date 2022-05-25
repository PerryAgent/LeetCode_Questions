class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<set<string>> dp;
        set<string> v = {""};
        dp.push_back(v);
        
        for(int i=1; i<=n; i++) {
            set<string> v;
            for (auto itr: dp[i-1]) {
                string s = "("+itr+")";
                v.insert(s);
            }
            for(int j=i-1; j>=1; j--) {
                for (auto itr : dp[j]) {
                    for (auto it: dp[i-j]) {
                        string s = it+itr; 
                        v.insert(s);
                    }
                }
            }
            
            dp.push_back(v);
        }
        vector<string> res;
        for(auto itr: dp[n]) {
            res.push_back(itr);
        }
        
        return res;
            
    }
};