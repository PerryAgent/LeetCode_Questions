class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int l=0;
        int h=nums.size()-1;
        int mid=-1;
        int f =0;
        while(l<=h) {
            mid = (l+h)/2;
            if(target==nums[mid]) {f++; break;}
            if(target<nums[mid]) h=mid-1;
            else l=mid+1;
        }
        cout << f << "\n";
        if(!f) return ans; 
        cout <<mid;
        l=0,h=mid;
        while(l<=h) {
            int m = (l+h)/2;
            if(target==nums[m]) 
                // && (m==0 || nums[m-1]!=target)) {
                ans[0]=m;
                // cout <<"here";
                // break;
            // }
            if(target<=nums[m]) h=m-1;
            else l=m+1;
        }
        
        l=mid, h=nums.size()-1;
        while(l<=h) {
            int m = (l+h)/2;
            if(target==nums[m])
                // && (m==nums.size()-1 || nums[m+1]!=target)) {
                ans[1] = m;
                // break;
            // }
            
            if(target>=nums[m]) l=m+1;
            else h=m-1;
        }
        
        return ans;
    }
};