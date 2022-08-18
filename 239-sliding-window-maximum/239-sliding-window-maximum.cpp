class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        // int mx = INT_MIN;
        multiset<int>mx;
        for(int i=0; i<k; i++) {
            if(i==nums.size()) break;
            mx.insert(nums[i]);
        }
        ans.push_back(*(--mx.end()));
        int p=0;
        int i=k;
        while(i<nums.size()) {
            mx.erase(mx.lower_bound(nums[p++]));
            mx.insert(nums[i++]);
            ans.push_back(*(--mx.end()));
        }
    
        return ans;
    }
};