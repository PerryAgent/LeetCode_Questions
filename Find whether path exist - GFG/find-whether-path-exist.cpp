// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        pair<int, int> t = {-1, -1};
        pair<int, int> src = {-1, -1};
        pair<int, int> dest = {-1, -1};
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    src = {i,j};
                else if(grid[i][j] == 2)
                    dest = {i, j};
            }
        }
        
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        if (src == t || dest == t) return 0;
        
        vector<vector<int>>mv = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>>q;
        
        bool found = 0;
        q.push(src);
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if (vis[i][j]) 
                continue;
            if (curr == dest) {
                found = 1;
                break;
            }
            
            vis[i][j] = 1;
            for(auto m: mv) {
                if (i+m[0] >=0 && i+m[0] < grid.size() && j+m[1] >=0 && j+m[1] <grid[0].size()){
                    if(!vis[i+m[0]][j+m[1]] && grid[i+m[0]][j+m[1]])
                        q.push({i+m[0], j+m[1]});
                }
            }
        }
        
        return found;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends