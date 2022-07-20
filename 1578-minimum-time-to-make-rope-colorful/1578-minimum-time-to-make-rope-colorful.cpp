class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int t =0;
        int n=time.size();
        int f = 0;
        for(int i=1; i<n; i++) {
            if(colors[i]==colors[f]){
                if(time[f]<=time[i]){
                    t += time[f];
                    f = i;
                } else {
                    t+= time[i];
                }
            }
            else
                f = i;
        }
        
        return t;
    }
};