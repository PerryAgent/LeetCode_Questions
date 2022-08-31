class Solution {
public:
    void getPerm(set<int>& nums, vector<vector<int>>& ans, vector<int> curr) {
        for(auto i: nums) {
            set<int> rem;
            for(auto j: nums)
                if(i!=j) rem.insert(j);
            curr.push_back(i);
            if(rem.size()==0) ans.push_back(curr);
            else getPerm(rem, ans, curr);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        // ans.push_back(nums);
        set<int>n;
        for(auto i: nums)
            n.insert(i);
        vector<int> curr;
        getPerm(n, ans, curr);
        return ans;
    }
};