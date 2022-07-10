// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        
        vector<int>anss(n, -1);
        return dp(n, 0, anss);
    }
    
    int dp(int n, int c, vector<int>&anss) {
        if (c==n) return 0;
        if (c>n) return INT_MAX;
        if (anss[c]!=-1) return anss[c];
        if (c == 0) return 1+ dp(n, c+1, anss);
        anss[c] = 1+ min(dp(n, c+1, anss), dp(n, c*2, anss));
        return anss[c];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends