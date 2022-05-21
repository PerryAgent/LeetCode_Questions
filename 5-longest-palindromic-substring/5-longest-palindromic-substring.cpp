class Solution {
public:
    
    string longestPalindrome(string s) {
        vector<vector<int>> dp;
        int maxl = 0;
        int l=-1,h=-1;
        
        for(int i=0; i<s.length(); i++) {
            vector<int> row(s.length(),0);
            dp.push_back(row);
        }
        
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            l = i;
            h = i;
            maxl = 1;
        }
        
        
        for(int j=0; j<=n-1; j++) {
            
            for(int i=n-1; i>=0; i--) {
                if(j<i) {
                    dp[i][j] = -1;
                    continue;
                }
                if(i==j)
                    continue;
                
                if(s[i] == s[j] && dp[i+1][j-1] != 0) {
                   
                        dp[i][j] = 1;
                       
                        if(maxl < j+1-i) {
                            
                            maxl = j+1-i;
                            l = i;
                            h = j;
                            
                        }
                    
                }
            }
        }
        
        return s.substr(l,h+1-l);
    }
                    

    };