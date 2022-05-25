class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=nums[0];
        int ct=0;
        
        for(int i=1;i<nums.size();i++)
        {
            ct+=(nums[i]-temp);
        }
    
        return ct;
    }
};