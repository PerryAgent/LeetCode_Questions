class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int>dig;
        long long cp = num;
        if(num<0) num*=-1;
        while(num>0) {
            dig.push_back(num%10);
            num/=10;
        }
        
        sort(dig.begin(), dig.end());
        if(cp<0) reverse(dig.begin(), dig.end());
        
        long long int nm=0;
        if(dig.size() == 0) return 0;
        int i=0;
        
        if(dig[0]==0) {
            
            while(dig[i]==0) i++;
            nm = nm*10 + dig[i];
            for(int j=0; j<i; j++)
                nm = nm*10;
            i++;
        }
        
        while(i<dig.size())
            nm = nm*10 + dig[i++];
        if(cp < 0) return nm*-1;
        return nm;
        
    }
};