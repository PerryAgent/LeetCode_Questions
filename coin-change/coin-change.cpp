class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>>mon(coins.size(), vector<int>(amount+1, -1));
        for(int i=0; i<coins.size(); i++)
            mon[i][0] = 0;
        for(int i=1; i<amount+1; i++)
        {
            if(i%coins[0]==0) mon[0][i] = i/coins[0];
        }
        // for(auto x: mon){
        //     for(auto y: x)
        //         cout << y << " ";
        //     cout << endl;
        // }
        for(int i=1; i<amount+1; i++) {
            for(int j=1; j<coins.size(); j++) {
                
                int a;
                if (i-coins[j] < 0)
                    a = -1;
                else
                    a = mon[j][i-coins[j]];
                int b = mon[j-1][i];
                
                if(a==-1)
                {
                    mon[j][i] = b;
                } else
                {
                    if(b==-1)
                        mon[j][i] = a + 1;
                    else
                        mon[j][i] = min(1+a, b);
                }
                
            }
        }
        
        
        return mon[coins.size()-1][amount];
    }
};