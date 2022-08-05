class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        set<int>next;
//         stack<pair<int, int>>n;
//         for(int i=0; i<nums.size(); i++) {
//             if(n.empty() || nums[i] <= n.top().first) {
//                 n.push({nums[i], i});
//             } else {
//                 while(!n.empty()){
//                     if(n.top().first < nums[i]) {
//                         next[n.top().second] = i;
//                         n.pop();
//                     } else
//                         break;
//                 }
//                 n.push({nums[i], i});
//             }
//         }
        
//         for(int i=0; i<next.size(); i++) {
//             if(next[i] != -1) {
//                 if(next[next[i]]!=-1) {
//                     return true;
//                 }
//             }
//         }
//         return false;
        for(int i=0; i<nums.size(); i++) {
            // for(auto it: next) cout << it << " ";
            // cout << endl;
            if(next.empty() || *(--(next.end())) < nums[i]) {
                // cout<<1<<endl;
                next.insert(nums[i]);
            } else {
                if(next.find(nums[i]) == next.end())
                    next.erase(*(upper_bound(next.begin(), next.end(), nums[i])));
                next.insert(nums[i]);
            }
            
            if(next.size() >= 3) {
                // for(auto it: next) cout << it << " ";
                return true;
            }
        }
        
        return false;
    }
};