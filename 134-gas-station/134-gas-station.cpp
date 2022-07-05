class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int t_gas = 0, s_gas = 0;
        for(int i=0; i<gas.size(); i++){
            int temp = gas[i] - cost[i];
            s_gas += temp;
            t_gas += temp;
            if(s_gas < 0)
            {
                start = i+1;
                s_gas = 0;
            }
            
        }
        
        if (t_gas >= 0)
            return start;
        return -1;
    }
};