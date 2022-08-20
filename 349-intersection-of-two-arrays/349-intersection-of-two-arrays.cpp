class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>a2;
        for(auto i: nums2) {
            a2.insert(i);
        }
        
        set<int>inter;
        for(auto i: nums1) {
            if(a2.find(i)!=a2.end()) inter.insert(i);
        }        
    
        vector<int>ans;
        for(auto i: inter)
            ans.push_back(i);
        
        return ans;
    }
    
};