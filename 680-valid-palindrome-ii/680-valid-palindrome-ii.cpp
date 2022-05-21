class Solution {
public:
    bool validPalindrome(string s) {
        string st = s;
        reverse(st.begin(), st.end());
        int f = 1;
        for(int i=0; i<s.length(); i++){
            // if (s[i]!=st[i] && f==0) {
            //     cout <<"2\n";
            //     return false;
            // }
            if(s[i]!=st[i]) {
                f--;
                string s1 = s.substr(0,i)+s.substr(i+1, s.length()-i-1);
                string st1 = s1;
                reverse(st1.begin(),st1.end());
                // cout << (st1 == s1) <<" ";
                if (s1==st1) {
//                     s = s1;
//                     st = st1;
                    cout << "1\n";
                    return (s1 == st1);
                }
                st = st.substr(0,i)+st.substr(i+1, st.length()-i-1);
                s = st;
                reverse(s.begin(),s.end());
                // cout << (st == s) <<" ";
                // if (s[i]!=st[i]) {
                //     cout <<"1\n";
                //     return false;
                // }
                cout <<"2\n";
                return (s==st);
                    
            }
        }
        return true;
    }
};