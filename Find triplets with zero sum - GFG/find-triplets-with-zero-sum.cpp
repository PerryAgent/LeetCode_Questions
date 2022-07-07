// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        vector<int> a;
        for(int i=0; i<n; i++) {
            a.push_back(arr[i]);
        }
        
        sort(a.begin(), a.end());
        int lp = 0, rp = a.size()-1;
        int sum = 0;
        int f = 0;
        for(int i=0; i<n; i++) {
            int lp = i+1;
            int rp = n-1;
            while(lp<rp) {
                if (a[i] + a[lp] + a[rp] < 0)
                    lp++;
                else if (a[i] + a[lp] + a[rp] > 0)
                    rp--;
                else
                    return 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends