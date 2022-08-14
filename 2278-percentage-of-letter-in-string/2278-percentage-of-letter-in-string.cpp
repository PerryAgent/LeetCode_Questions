class Solution {
public:
    int percentageLetter(string s, char letter) {
        int c = 0;
        for(auto i: s) {
            if(i==letter) c++;
        }
        return (int)(((c*1.0)/s.size())*100);
    }
};