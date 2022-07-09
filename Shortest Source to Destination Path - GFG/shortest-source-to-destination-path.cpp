// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>>distance(N, vector<int>(M, INT_MAX));
        vector<vector<bool>>visited(N, vector<bool>(M, false));
        
        
        queue<pair<int, int>>q;
        q.push({0,0});
        vector<vector<int>>mv = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        distance[0][0] = 0;
        int found = 0;
        while(!q.empty()) {
            
            pair<int, int> curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            if(curr.first == X && curr.second == Y){
                found++;
                break;
            }
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            if(A[i][j] == 0)
             return -1;
            for(auto m: mv){
                if (i+m[0] >= 0 && i+m[0] < N && j+m[1] >= 0 && j+m[1] < M) {
                    pair<int, int>p = {-1, -1};
                    pair<int, int>p1 = {i+m[0], j+m[1]};
                    if (visited[i+m[0]][j+m[1]] == 0 && A[i+m[0]][j+m[1]] == 1){
                        q.push({i+m[0], j+m[1]});
                        distance[i+m[0]][j+m[1]] = distance[i][j] + 1;
                    }
                }
            }
        }
        
        if (!found)
         return -1;
         
        int ans = distance[X][Y];

        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends