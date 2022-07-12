// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>grid(n, vector<int>(m, 0));
        
        int mx = 0;
        pair<int, int>pr = {-1,-1};
        grid[0][0] = (int)(S1[0]==S2[0]);
        for(int i=0; i<n; i++) {
            if(S1[i]==S2[0]){
                grid[i][0] = 1;
                pr = {i, 0};
                mx = 1;
            }
        }
        
        for(int i=0; i<m; i++) {
            if(S1[0]==S2[i]){
                grid[0][i] = 1;
                pr = {0, i};
                mx = 1;
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(S1[i]==S2[j]){
                    grid[i][j] = 1+grid[i-1][j-1];
                    mx = max(mx, grid[i][j]);
                }
            }
        }
        
        return mx;
        
        //abcdefa babdcf
        
        /*
        3
        accb abcc
        adbc abc
        i j-1
        i-1 j
        i-1 j-1
        0 6
        1
        2
        3
        4 60+5 = 65
        5
        
        0 1 2 3 4  5  8 10 
        0 2 4 6 8 10 60  50 
        
        0 1 2 3 4 5 6 7 8 9
    0 --
    1   
    2
    3
    4
    5
    6
        
        01
        a   b  c
    a   00  -1,-1  0
    d   0   0  0
    b   0   2,1  0
    c   0   0   
        
        0 2
        1
        3
        4
        5
        
        
        
        */
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends