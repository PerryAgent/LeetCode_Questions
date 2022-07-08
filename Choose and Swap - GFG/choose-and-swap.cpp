// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
// aabbcd
// abbadc
    string chooseandswap(string a){
        // Code Here
        // char s = a[0];
        // set<char>found;
        // string n_str = ""
        // map<char, vector<int>>letters;
        // for(int i=0; i<a.size(); i++){
        //     if (a[i] >= s) {
        //         s = a[i];
                
        //         if (found.find(s) == found.end()){
                    
        //             found.insert(s);
        //             letters[s] = {};
        //             letters[s].push_back(i);
                    
        //         }
        //         n_str.push_back(s);
        //         continue;
        //     }
            
        //     int j = i;
        //     char swap = s;
        //     while(j<a.size()) {
        //         if (found.find(a[j]) == found.end()) {
        //             if (a[j] < swap)
        //                 swap = a[j];
        //         }
        //         j++;
        //     }
        //     if ()
        
        
        vector<int>firstIndex(26, -1);
        for(int i=0; i<a.size(); i++) {
            if (firstIndex[a[i]-'a'] == -1)
                firstIndex[a[i]-'a'] = i;
        }
        
        
        int i, j;
        for(i=0; i<a.size(); i++) {
            int f = 0;
            for(j=0; j<a[i]-'a'; j++) {
                if(firstIndex[j]>firstIndex[a[i]-'a']){
                    f++;
                    break;
                }
            }
            if (f) break;  
        }
        
        
        if (i>=a.size()) return a;
        
        char one = a[i];
        char two = j+'a';
        
        for(int k=0; k<a.size(); k++){
            if(a[k] == one)
                a[k] = two;
            else if(a[k] == two)
                a[k] = one;
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends