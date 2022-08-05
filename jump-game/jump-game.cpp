class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>jmp(nums.size(), 0);
        jmp[nums.size()-1] = 1;
        for(int i=nums.size()-2; i>=0; i--) {
            for(int j=nums[i]; j>=1; j--) {
                if(i+j >= nums.size() || jmp[i+j]){
                    jmp[i] = 1;
                    break;
                }
            }
        }
        
        return jmp[0];
    }
};