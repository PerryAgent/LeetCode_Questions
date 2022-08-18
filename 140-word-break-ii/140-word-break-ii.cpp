class Solution {
public:
    void findSent(int p, int i, string s, set<string>& dict, vector<string>& sent, string T) {
        string t = s.substr(p, i-p+1);
        if(dict.find(t)==dict.end()) {
            if(i==s.size()-1) return;
            findSent(p, i+1, s, dict, sent, T);
            return;
        } 
        
        if(i == s.size()-1) sent.push_back(T+t);
        else{
            findSent(i+1, i+1, s, dict, sent, T+t+" ");
            findSent(p, i+1, s, dict,sent, T);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>dict;
        vector<string> sent;
        for(auto i: wordDict) {
            dict.insert(i);
        }
        vector<string> ans;
        
        findSent(0, 0, s, dict, ans, "");
        return ans;
    }
};