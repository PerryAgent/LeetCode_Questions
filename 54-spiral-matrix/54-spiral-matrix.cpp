class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m0=0,n0=0,m1=matrix.size()-1,n1=matrix[0].size()-1;
        int t=(m1+1)*(n1+1);
        while(t>0) {
            
            for(int j=n0; j<=n1; j++) {
                
                if(t==0)
                    break;
                ans.push_back(matrix[m0][j]);
                t--;
            }
            m0++;
            for(int i=m0; i<=m1; i++) {
                
                if(t==0)
                    break;
                ans.push_back(matrix[i][n1]);
                t--;
            }
            n1--;
            for(int j=n1; j>=n0; j--) {
                //t--;
                if(t==0)
                    break;
                ans.push_back(matrix[m1][j]);
                t--;
            }
            m1--;
            for(int i=m1; i>=m0; i--) {
                //t--;
                if(t==0)
                    break;
                ans.push_back(matrix[i][n0]);
                t--;
            }
            n0++;
        }
        return ans;
    }
};