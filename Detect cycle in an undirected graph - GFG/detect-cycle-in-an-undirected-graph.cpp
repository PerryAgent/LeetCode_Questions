// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    set<int> visited;
    bool hasCycle = false;
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0; i< V; i++){
            if (visited.find(i) == visited.end())
                dfs(adj, i, -1);
            if (hasCycle == true) return true;
        }
     
        return hasCycle;   
    }
    
    void dfs(vector<int> adj[], int i, int p) {
        if (visited.find(i) != visited.end())
         {
            //  cout << i << "\n";
             hasCycle = true;
             return;
         }
        
        visited.insert(i);
        
        for(auto j: adj[i]) {
            if (j!=p)
                dfs(adj, j, i);
            if (hasCycle) return;
        }
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends