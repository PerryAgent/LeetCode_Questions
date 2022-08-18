class Solution {
public:
    
    long long findLeast(vector<int>& psq, int i, int s, vector<vector<int>>&m)
    {
        if(s==0)
            return 0;
        if(i==psq.size()) return INT_MAX;
        
        if(psq[i] > s) return INT_MAX;
        if(m[i][s] != -1)
            return m[i][s];
        return m[i][s] = min(1ll+findLeast(psq, i, s-psq[i], m), findLeast(psq, i+1, s, m));
    }
    int numSquares(int n) {
        vector<int>psq;
        for(int i=1; i<=sqrt(n); i++) {
            psq.push_back(i*i);
        }
        vector<vector<int>>m(psq.size(), vector<int>(n+1, -1));
        long long ans = findLeast(psq, 0, n, m);
        return ans;
    }
};