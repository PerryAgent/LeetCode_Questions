// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int start = 0;
        int sum = 0;
        int end = 0;
        for(int i=0; i<n; i++) {
            if (sum + arr[i] < s)
                sum += arr[i];
            else if (sum + arr[i] == s)
            {    end = i;
                 sum += arr[i];
                 break;
            } else {
                sum = sum + arr[i];
                while(sum > s) {
                    sum -= arr[start++];
                }
                start;
                if (sum == s) {end = i; break;}
            }
        }
        if (sum!=s || start > end) {vector<int> ans; ans.push_back(-1); return ans;}
        
        vector<int> ans;
        ans.push_back(++start);
        ans.push_back(++end);
        return ans;
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
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends