// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<vector<int>> out(V, vector<int>());
	    vector<vector<int>> in(V, vector<int>());
	    
	    int start = -1;
	    for(int i=0 ;i<V; i++) {
	        for(auto nbr: adj[i]) {
	            out[i].push_back(nbr);
	            in[nbr].push_back(i);
	        }
	    }


        queue<int>q;
        vector<int>visited(V,0);
	    
	    vector<int> ans;
	    for(int i=0; i<V; i++) {
	        if (in[i].size() == 0) {
	            start = i;
	            ans.push_back(start);
	            visited[start] = 1;
	            for(auto nbr: adj[start]) {
	                q.push(nbr);
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int i = q.front();
	        q.pop();
	        int f = 0;
	        if (visited[i] == 1) continue;
	        for(auto nbr: in[i]){
	            if (visited[nbr] == 0){
	                f++;
	                q.push(nbr);
	                break;
	                
	            }
	        } 
	        if (!f) {
	            visited[i] = 1;
	            ans.push_back(i);
	            for (auto nbr: adj[i]) {
	                q.push(nbr);
	            }
	        }
	    }
	    
	   // for(auto i: ans)
	   //     cout << i << " ";
	    return ans;
	    
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends