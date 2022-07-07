// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=0;
        vector<vector<int>> move = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i=0; i<grid.size(); i++) {
            for(int j= 0; j<grid[0].size(); j++) {
                if (visited[i][j] == 1) continue;
                if (grid[i][j] == '1') {
                    
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    n +=1;
                    while(!q.empty()) {
                    
                        pair<int, int> pos = q.front();
                        
                        q.pop();
                        if(visited[pos.first][pos.second] == 1) continue;
                       
                        visited[pos.first][pos.second] = 1;
                        int k = pos.first;
                        int l = pos.second; 
                        for(auto d: move) {
                            if (k+d[0] >= 0 && k+d[0] <grid.size() && l+d[1] >=0 && l+d[1] <grid[0].size()) {
                                if (grid[k+d[0]][l+d[1]] == '1') {
                                    q.push({k+d[0], l+d[1]});
                                }
                            }
                        }
                    }
                    
                } else {
                    
                    visited[i][j] = 1;
                }
            }
        }
        
        return n;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends