// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    // Function to detect cycle in a directed graph.
    set<int> visited;
    bool hasCycle = false;
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> lvisited(V, false);
        for(int i=0;  i<V; i++) {
            if (visited.find(i) == visited.end())
                dfs(i, adj, lvisited);
            if (hasCycle) return true;
            
            // for(auto j: visited) cout << j << "\n";
        }
        
        return hasCycle;
    }
    
    void dfs(int i, vector<int> adj[], vector<bool> &lvisited) {
        
        lvisited[i] = true;;
        visited.insert(i);
        
        for(auto j: adj[i]) {
            if (visited.find(j) == visited.end()) {
               
                dfs(j, adj, lvisited);
                if(hasCycle) return;
            } else if (lvisited[j] == true){
                hasCycle = true;
                return;
            }
        }
            
        lvisited[i] = false;
        
            
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends