class Solution {
public:
    void swap(int p, int i, vector<int>& nums) {
        int t = nums[i];
        nums[i] = nums[p];
        nums[p] = t;
    }
    int firstMissingPositive(vector<int>& nums) {
        int p=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 0)
                swap(p++, i, nums);
        }
        
        cout << p<< endl;
        
        for(long int i=p; i<nums.size(); i++) {
            if((nums[i]*1ll)+p-1ll < nums.size() && (nums[i]*1ll)+p-1ll!=i) {
                if(nums[(nums[i]*1ll)+p-1ll] == nums[i]) continue;
                swap(i, (nums[i]*1ll)+p-1ll, nums);
                i--;
            }
        }
        
        for(auto i: nums) cout << i<<" ";
        
        int n = 1;
        for(int i=p; i<nums.size(); i++) {
            if(nums[i] != n) return n;
            n++;
        }
        
        return n;
    }
};