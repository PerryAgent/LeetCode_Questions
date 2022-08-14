class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0, r=colors.size()-1;
        int mn = 0;
        while(l<r){
            if(colors[l]!=colors[r]){
                mn = r-l;
                break;
            }
            r--;
        }
        l=0, r=colors.size()-1;
        while(l<r){
            if(colors[l]!=colors[r]){
                mn = max(mn, r-l);
                break;
            }
            l++;
        }
    return mn;
    }
};