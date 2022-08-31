class Solution {
public:
    int search(vector<int>& nums, int target) {
     //  6 7 0 1 2 4 5   
        int rl =0, h = nums.size()-1;
        while(rl <h) {
            int mid = (rl+h)/2;
            if(nums[mid]>nums[h])
                rl = mid+1;
            else h = mid;
        }
        int l=0;
        h = nums.size()-1;
        while(l<=h) {
            int mid = (l+h)/2;
            int rmid = (rl+mid)%nums.size();
            if(nums[rmid]==target) return rmid;
            if(nums[rmid]<target) l=mid+1;
            else h=mid-1;
        }
        
        return -1;
    }
};