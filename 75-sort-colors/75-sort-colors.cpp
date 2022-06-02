class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lp = 0;
        int rp = nums.size()-1;
        int ep = 0;
        
        while(lp<=rp) {
            cout <<lp<<" "<<ep<<" "<<rp<<"\n";
            if (nums[lp] == 0) {
                swap(nums[lp], nums[ep]);
                lp++;
                ep++;
                continue;
            }
            
            if (nums[lp] == 1) {
                lp++;
                continue;
            }
            
            if (nums[lp] == 2) {
                swap(nums[lp], nums[rp]);
                rp--;
                continue;
            }
            cout <<lp<<" "<<ep<<" "<<rp<<"\n";
            
        }

//             cout << lp <<rp<<"\n";
//             if (nums[rp] < nums[lp]) {
//                 int temp = nums[lp];
//                 nums[lp] = nums[rp];
//                 nums[rp] = temp;
//             }
            
//             while (lp <= nums.size()-1){
//                 cout <<"h";
//                 if (nums[lp] == 0){cout <<lp <<"\n";
//                 lp++;}
//             else{
//                 cout<<"bye\n";
//                 break;}}
            
//             while (rp>=0){
//                 cout<<"k";
//                 if(nums[rp] == 2){cout << rp<<"\n";
//                 rp--;}
//             else{
//                 cout<<"bye\n";
//                 break;}}
            
//             cout <<lp<< " "<<rp;
            
//             if(lp<nums.size()-1 && nums[lp] == 1 && rp>0 && nums[rp] == 1 )
//             {
//                 cout <<"hello";
//                 if(nums[lp]>nums[lp+1]){
//                     int temp = nums[lp];
//                     nums[lp] = nums[lp+1];
//                     nums[lp+1] = temp;
//                 }
//                     lp++;
                
//                 if(nums[rp]<nums[rp-1]){
//                     int temp = nums[rp];
//                     nums[rp] = nums[rp-1];
//                     nums[rp-1] = temp;
//                 }
            
//                     rp--;
//             }
            
//             cout <<lp<< " "<<rp;
//         }

            
        }
};