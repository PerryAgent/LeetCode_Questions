// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
    
   
        
        vector<int>cache;
        int lru;
        int fault = 0;
        for (int i=0; i<n; i++) {
            auto it = find(cache.begin(), cache.end(), pages[i]);
            if (it == cache.end()) {
                if (cache.size() == c) {
                    cache.erase(cache.begin());
                }
                
                cache.push_back(pages[i]);
                fault++;
            } else {
                cache.erase(it);
                cache.push_back(pages[i]);
            }
        }
        
        return fault;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends