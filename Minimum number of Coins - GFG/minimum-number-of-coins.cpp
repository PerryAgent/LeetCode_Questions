// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int>den = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>change;
        while(N>0) {
            for(auto i: den){
                if(i <= N) {
                    for(int j=0; j<N/i; j++)
                        change.push_back(i);
                    N = N%i;
                }
            }
        }
        /*
        11
        7 6 5 1
        7
        1 1 1 1
        
        */
        
        return change;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends