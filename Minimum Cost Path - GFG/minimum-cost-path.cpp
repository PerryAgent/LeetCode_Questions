// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        vector<vector<int>>cost(grid.size(), vector<int>(grid.size(), INT_MAX));
        cost[0][0] = grid[0][0];
        
        set<pair<int, pair<int, int>>>mnCost;
        mnCost.insert({grid[0][0], {0,0}});
        
        vector<vector<int>>mv ={{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(!mnCost.empty()) {
            pair<int, pair<int, int>>temp = *mnCost.begin();
            pair<int, int> curr = temp.second;
            int currCost = temp.first;
            int i = curr.first;
            int j = curr.second; 
            mnCost.erase(mnCost.begin());
            
            for(auto m: mv){
                int x = i+m[0];
                int y = j+m[1];
                
                if(x>=0 && x<grid.size() && y>=0 && y<grid.size()) {
                    if(cost[x][y] > cost[i][j] + grid[x][y]) {
                        if(cost[x][y] != INT_MAX)
                            mnCost.erase(mnCost.find({cost[x][y], {x, y}}));
                            
                        cost[x][y] = cost[i][j] + grid[x][y];
                        mnCost.insert({cost[x][y], {x, y}});
                    }
                }
            }
            
            
            
        }
        
        return cost[grid.size()-1][grid.size()-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends