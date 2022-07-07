// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    // int recur(vector<pair<int, int>>&events, int st, int en) {
    //     if (st >= en) return 0;
        
    //     int ene = -1;
    //     int ans = 0;
    //     for(auto i: events){
    //         if(st>=i.first) {
    //             st = i.first;
    //             ene = i.second;
    //             ans = max(ans, recur(events, st)
    //             break;
    //         }
    //     }
    //     return max(1+recur(events, ene+1, en), )
    // }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int st = INT_MAX, en = INT_MIN;
        
        vector<pair<int, int>> events;
        for(int i=0; i< start.size();i++) {
            st = min(st, start[i]);
            en = max(en, end[i]);
            events.push_back({end[i], start[i]});
        }
        
        sort(events.begin(), events.end());
        
        int ans = 0;
        int l_end = -1;
        for(auto i: events) {
            if (i.second > l_end) {
                ans++;
                l_end  = i.first;
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends