class Solution {
public:
    map<pair<int, int>, int>dict;
    int paths(int i, int j, vector<vector<int>>& grid) {
        if(grid[i][j]) return 0;
        if(i== grid.size()-1 && j==grid[0].size()-1)
            return 1;
        
        if(dict.find({i,j}) != dict.end()) return dict[{i,j}];
        int d= 0, r = 0;
        if(i+1 < grid.size() && grid[i+1][j] != 1) d = paths(i+1, j, grid);
        if(j+1 < grid[0].size() && grid[i][j+1] != 1) r = paths(i, j+1, grid);
        
        return dict[{i,j}] = d+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int p = paths(0, 0, grid);
        return p;
    }
};