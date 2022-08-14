class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        //declaring a vector pair
        vector<pair<long long,int>>vec;
        //the first element is of long long type because
        //-2^31 <= nums[i] <= 2^31 - 1
        
        //'vec' stores the pair of (nums[i],i)
        //that is element and its index
        
        for(int i=0; i<n; i++)
        {
            vec.push_back(make_pair(nums[i],i));
        }
        
        //sorting vec according to nums[i]
        sort(vec.begin(), vec.end());
        
        //traversing the vector after sorting
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //checking the first condition
                if(abs(vec[i].first - vec[j].first)<=t)
                {
                    //checking the second condtion
                    if(abs(vec[i].second - vec[j].second)<=k)
                    {
                        return true;
                    }
                }
                else
                {
                    //if the first condtion is not followed by (i,j) pair
                    //since the vector is sorted
                    //no other pair will be able to fulfill the first condition
                    //hence we break out of the second loop
                    break;
                }
            }
        }
        
        return false;
    }
};