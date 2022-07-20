class Solution {
public:
    void dfs(int i, vector<vector<int>>& edges, vector<int>& itime, vector<int>& ttime, int t) {
        ttime[i] = t;
        for(auto j: edges[i]) {
            dfs(j, edges, itime, ttime, t+itime[i]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>edges(n, vector<int>());
        for(int i=0; i<n; i++) {
            if(manager[i]!=-1)
                edges[manager[i]].push_back(i);
        }
        
        vector<int>ttime(n,0);
        dfs(headID, edges, informTime, ttime, 0);
        
        int m = INT_MIN;
        for(int i=0; i<n; i++) {
            m = max(m, ttime[i]);
        }
        
        return m;
    }
};