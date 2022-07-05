class Solution {
public:
    int minDeletions(string s) {
        map<char, int> freq;
        set<int> num;
        for(auto i: s) {
            if (freq.find(i) != freq.end())
                freq[i]++;
            else
                freq[i] = 1;
        }
        
        for(auto i: freq) {
            cout << i.first << i.second <<endl;
        }
        
        int ans = 0;
        for(auto i: freq) {
            if (num.find(i.second) == num.end()){
                cout << i.first << i.second <<endl;
                num.insert(i.second);
                continue;
            }
            while(num.find(i.second) != num.end()){
                cout << i.first << i.second<<endl;
                i.second -= 1;
                ans += 1;
            }
            if (i.second != 0)
                num.insert(i.second);
        }
        
        return ans;
        
    }
};