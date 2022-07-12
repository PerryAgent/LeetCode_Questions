// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int>den = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    
    vector<int> minPartition(int N)
    {
        // code here
        vector<vector<int>>change(den.size(), vector<int>(N+1));
        // while(N>0) {
        //     for(auto i: den){
        //         if(i <= N) {
        //             for(int j=0; j<N/i; j++)
        //                 change.push_back(i);
        //             N = N%i;
        //         }
        //     }
        // }
        /*
        11
        7 6 5 1
        7
        1 1 1 1
        
        0 1 2 3 4 5 6 7 8 9 10 11
    1   0 1 2 3 4 5 6 7 8 9 10 11
    5   0 1 2 3 4 1 2 3 4 5 2  3
    6   0 1 2 3 4 1 1 2 3 4 5  2
    7   0 1 2 3 4 1 1 1 2 3 4  5
    
        
        */
        
        for(int i=0; i<den.size(); i++) {
            change[i][0] = 0;
        }
        
        for(int i=0; i<=N; i++) {
            change[0][i] = i;
        }
        
        for(int i=1; i<den.size(); i++) {
            for(int j=1; j<=N; j++) {
                change[i][j] = (j/den[i]) + change[i-1][j%den[i]];
            }
        }
        
        vector<int>ans;
        int im;
        int mn = INT_MAX;
        for(int i=0; i<den.size(); i++) {
        //  mn = min(mn, );  
         if (mn > change[i][N]){
             mn = change[i][N];
             im = i;
         }
        }
        
        while(N>0) {
            for(int i=0; i<N/den[im]; i++)
                ans.push_back(den[im]);
            N = N%den[im];
            im--;
        }
        
        return ans;
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