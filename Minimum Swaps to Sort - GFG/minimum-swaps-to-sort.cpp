// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int swaps = 0;
	    map<int, int>indices;
	    vector<int>copy = nums;
	    sort(copy.begin(), copy.end());
	    for(int i=0; i<nums.size(); i++) {
	        indices[copy[i]] = i;
	    }
	    int i=0;
	    vector<bool>vis(nums.size(), false);
	    while(i<nums.size())
	    {
	        if (vis[i] || copy[i] == nums[i]) {i++; continue;}
	        
	        int cycle_size = 0;
	        int j = i;
	        while(!vis[j]) {
	            vis[j] = 1;
	            j = indices[nums[j]];
	            cycle_size++;
	        }
	        
	        if (cycle_size > 0)
	            swaps+=(cycle_size-1);
	        i++;
	    }
	    
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends