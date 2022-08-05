class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>>pal(s.size(), vector<int>(s.size(), -1));
        for(int i=0; i<s.size(); i++)
            pal[i][i] = 1;
        for(int i=s.size()-2; i>=0; i--) {
            for(int j=i+1; j<s.size(); j++) {
                if(s[i]!=s[j]) {
                    pal[i][j] = 0;
                } else {
                    pal[i][j] = pal[i+1][j-1]!=0;
                }
            }
        }
        
        // for(int i=0; i<s.size(); i++) {
        //     for(int j=0; j<s.size(); j++)
        //         cout << pal[i][j] <<" ";
        //     cout << endl;
        // }
        
        int mxi = -1, mxj = -1;
        int mx = INT_MIN;
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<s.size(); j++) {
                if(pal[i][j]) {
                    if(mx < j-i+1){
                        mx = j-i+1;
                        mxi = i;
                        mxj = j;
                    }
                }
            }
        }
        
        return s.substr(mxi, mxj-mxi+1);
    }
};