class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = 1;
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};
        
        for(int x=0; x<4; x++) {
                int ix = i+dx[x];
                int jy = j+dy[x];

                if(ix >=0 && ix < grid.size() && jy >=0 && jy < grid[0].size())
                    if(!visited[ix][jy] && grid[ix][jy] == '1'){
                        cout << "yes\n";
                        dfs(ix, jy, visited, grid);
                    // for(auto xi: visited) {
                    //     for(auto yi: xi) {
                    //         cout << yi << " ";
                    //     }
                    //     cout  << endl;
                    // }
                    }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, visited, grid);
                    // for(auto x: visited) {
                    //     for(auto y: x) {
                    //         cout << y << " ";
                    //     }
                    //     cout  << endl;
                    // }
                }
            }
        }
        
        return islands;
    }
};