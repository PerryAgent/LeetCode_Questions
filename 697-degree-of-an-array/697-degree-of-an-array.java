class Solution {
    public int findShortestSubArray(int[] nums) {
        HashMap<Integer, Integer> first = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> last = new HashMap<Integer, Integer>();
        int mf=0;
        for(int i=0; i<nums.length; i++) {
            if(first.get(nums[i])==null) first.put(nums[i], i);
            if(freq.get(nums[i])==null) freq.put(nums[i], 1);
            else freq.put(nums[i], freq.get(nums[i])+1);
            mf = freq.get(nums[i]) > mf ? freq.get(nums[i]) : mf;
            last.put(nums[i], i);
        }
        
        int ans = nums.length;
        for(int i: nums) {
            if(freq.get(i)==mf) ans = last.get(i)-first.get(i)+1 < ans ? last.get(i)-first.get(i)+1 : ans;
        }
        
        return ans;
         
    }
}