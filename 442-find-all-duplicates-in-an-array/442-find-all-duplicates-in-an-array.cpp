class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>ans;
        for(int i=0; i<nums.size();) {
            if(nums[i]-1==i) i++;
            else {
                if(nums[nums[i]-1]-1 == nums[i]-1) {
                    ans.insert(nums[i++]);
                    continue;
                }
                int t = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = t;
            }
        }
        
        vector<int>arr;
        for(auto i: ans) 
            arr.push_back(i);
        
        return arr;
    }
};