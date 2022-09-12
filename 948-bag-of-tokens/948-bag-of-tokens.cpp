class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l=0, r=tokens.size()-1;
        int s = 0;
        int sm = 0;
        sort(tokens.begin(), tokens.end());
        while(l<=r) {
            if(power>=tokens[l]) {
                cout << 1 << endl;
                power -= tokens[l];
                s++;
                sm = max(sm, s);
                l++;
            } else if(s>=1) {
                cout << 2 << endl;
                power += tokens[r];
                s--;
                r--;
            } else break;
        }
        
        return sm;
    }
};