class Solution {
public:
    int dis = 0;
    int cycles = 0;
    
    void dfs(vector<vector<int>>& connections, int i, vector<int>& visited, int p) {
        visited[i] = 1;
        
        for(auto j: connections[i]) {
            if(j!=p){
                // cout << j <<endl;
                if(visited[j]){
                    // cout << "here ";
                    cycles++;
                    // cout << cycles <<"\n";
                    continue;
                }
                dfs(connections, j, visited, i);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        dis = 0;
        cycles = 0;
        
        vector<int>visited(n, 0);
        vector<vector<int>> edges(n, vector<int>());
        
        for(auto i: connections) {
            edges[i[0]].push_back(i[1]);
            edges[i[1]].push_back(i[0]);
        }
        
        // for(auto i: edges) {
        //     for(auto j: i)
        //         cout << j <<" ";
        //     cout <<endl; 
        // }
        
        for(int i=0; i<n; i++) {
            if(!visited[i]){
                dis++;
                dfs(edges, i, visited, -1);}
        }
        
        
        
        // cout << dis << " "<<cycles<<"\n";
        
        if(dis-1 > cycles/2) {
            return -1;
        }
        
        return dis-1;
    }
};