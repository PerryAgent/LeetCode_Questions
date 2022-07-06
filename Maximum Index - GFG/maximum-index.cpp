// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        int start = 0, end = n-1;
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            start = i;
            end = n-1;
            while(start < end) {
                if(a[end] >= a[start]) {
                    ans = max(ans, end-start);
                    break;
                }
                // if(end-start-1 < ans) break;
                end--;
            }
        }
    
        return ans;
    }
    
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends