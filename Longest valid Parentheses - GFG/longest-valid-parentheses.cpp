// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        int l = 0, r = 0, maxi = INT_MIN, maxi1 = INT_MIN;
       bool x = false;
       for(int i=0; i<s.size(); i++) {
           if(s[i] == '(') {
               l++;
           }
           else if(s[i] == ')') {
               r++;
           }
           if(l==r) {
               maxi = max(maxi, 2*l);
               x = true;
           }
           else if(r > l) {
               l = 0, r = 0;
           }
       }
      
       l = 0, r = 0;
       for(int i=s.size()-1; i>=0; i--) {
           if(s[i] == '(') {
               l++;
           }
           else if(s[i] == ')') {
               r++;
           }
           if(l == r) {
               maxi1 = max(maxi1, 2*l);
               x = true;
           }
           else if(l > r) {
               l = 0, r = 0;
           }
       }
       if(x == true)
           return max(maxi,maxi1);
       return 0;
   }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends