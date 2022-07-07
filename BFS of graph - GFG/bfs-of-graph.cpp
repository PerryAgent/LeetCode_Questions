// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        vector<int> ans;
        queue<int> toBeVisited;
        
            toBeVisited.push(0);
            while(!toBeVisited.empty())
                bfs(adj, visited, ans, toBeVisited);
        
        return ans;
    }
    
    void bfs(vector<int> adj[], vector<int> &visited, vector<int> &ans, queue<int> &toBeVisited) 
    {
        int i = toBeVisited.front();
        toBeVisited.pop();
        if (visited[i] == 1) return;
        visited[i] = 1;
        ans.push_back(i);
        for (auto nbr: adj[i]) {
            if (visited[nbr] == 0)
            toBeVisited.push(nbr);
        }
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends