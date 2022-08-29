class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>grid(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i=0; i<=word1.size(); i++) {
            grid[i][0] = i;
        }
        
        for(int j=0; j<=word2.size(); j++) 
            grid[0][j] = j;
        
        for(int i=1; i<=word1.size(); i++) {
            for(int j=1; j<=word2.size(); j++) {
                // cout << word1[i-1] << " " << word2[j-1]<<endl;
                if(word1[i-1]==word2[j-1])
                    grid[i][j] = min(grid[i-1][j-1], min(grid[i][j-1]+1, grid[i-1][j]+1));
                else
                    grid[i][j] = 1 + min(grid[i-1][j-1], min(grid[i][j-1], grid[i-1][j]));
            }
        }
        
        // for(auto i: grid){
        //     for(auto j: i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        
        return grid[word1.size()][word2.size()];
        
    }
};