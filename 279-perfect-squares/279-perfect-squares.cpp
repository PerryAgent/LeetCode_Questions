class Solution {
public:
    
    int findLeast(vector<int>& psq, int i, int s, vector<vector<int>>&m)
    {
        if(s==0)
            return 0;
        if(i==psq.size()) return (int) 1e5;
        
        if(psq[i] > s) return (int) 1e5;
        if(m[i][s] != -1)
            return m[i][s];
        return m[i][s] = min(1+findLeast(psq, i, s-psq[i], m), findLeast(psq, i+1, s, m));
    }
    int numSquares(int n) {
        vector<int>psq;
        for(int i=1; i*i<=n; i++) {
            psq.push_back(i*i);
        }
        vector<vector<int>>m(psq.size(), vector<int>(n+1, -1));
        int ans = findLeast(psq, 0, n, m);
        return ans;
    }
};