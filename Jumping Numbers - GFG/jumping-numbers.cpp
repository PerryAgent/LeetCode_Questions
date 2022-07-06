// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    //1 -> 2 -> 3-> 4-> ... 9
    // 10 -> 12 -> 32 -> 34 
  public:
    long long jumpingNums(long long X) {
        // code here
        long long ans = 0;
        queue<long long> queue;
        for(int i=1; i<=9; i++) {
            if (i > X)
                return i-1;
            ans = i;
            queue.push(i);
        }
        
        while(!queue.empty()) {
            long long curr = queue.front();
            queue.pop();
            int r = curr% 10;
            
            if(r!=0){
                long long num = (curr*10) + (r-1);
                if (num <= X) {
                queue.push(num);
                ans = max(ans, num);
                    // cout << ans<< endl;
                }
            }
            if(r!=9){
                long long num = (curr*10) + (r+1);
                if (num <= X) {
                queue.push(num);
                ans = max(ans, num);
                    // cout <<ans << endl;
                }
            }
            
        }
        return ans;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}  // } Driver Code Ends