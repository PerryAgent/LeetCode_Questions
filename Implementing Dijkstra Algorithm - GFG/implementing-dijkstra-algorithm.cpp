// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>visited(V,0);
        set<int>vset;
        vector<int>distance(V, INT_MAX);
        distance[S] = 0;
        while(vset.size() != V) {
            int mn = INT_MAX;
            int u = -1;
            for(int i=0; i< V; i++) {
                if (visited[i] == 1) continue;
                if (mn > distance[i]) {
                    mn = distance[i];
                    u = i;
                }
            }
            vset.insert(u);
            visited[u] = 1;
            for(auto nbr: adj[u]) {
                distance[nbr[0]] = min(distance[nbr[0]], nbr[1]+distance[u]);
            }
        }
        
        return distance;
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends