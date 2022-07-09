// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        vector<int>dig(N, 0);
        
        for(int i=0; i<N; i++) {
            if (S==0)
                break;
            int a = 9;
            while(a > S)
                a--;
            S -= a;
            dig[i] = a;
        }
        
        string nstr = "";
        for(auto i: dig) {
            nstr += '0' + i;
        }
        
        if(nstr[0] == '0' && N != 1 || S > 0)
            return "-1";
        
        
        return nstr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends