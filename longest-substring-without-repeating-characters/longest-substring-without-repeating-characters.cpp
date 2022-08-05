class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = INT_MIN;
        unordered_map<char, int>chr;
        int p=0;
        for(int i=0; i<s.size(); i++) {
            if(chr.find(s[i])==chr.end()){
                chr[s[i]] = i;
                mx = max(mx, i-p+1);
            } else {
                if(p>chr[s[i]]+1)
                    chr[s[i]] = i;
                else
                    p=chr[s[i]]+1;
                chr[s[i]] = i;
                mx = max(mx, i-p+1);
            }
        }
        
        return max(mx, 0);
    }
};