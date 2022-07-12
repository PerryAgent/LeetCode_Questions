// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        int mn = 0, mx = 0;
        sort(candies, candies+N);
        int l = 0, r = N-1;
        while(l<=r) {
            mn += candies[l];
            if (r-l < k)
                r = l;
            else
                r -= k;
            l++;
        }
        l=0, r=N-1;
        while(l<=r) {
            mx+=candies[r];
            if(r-l <k)
                l=r;
            else
                l+=k;
            r--;
        }
        
        vector<int>ans = {mn, mx};
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends