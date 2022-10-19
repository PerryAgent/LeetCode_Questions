class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        for(auto i: words)
            mp[i]++;
        
        set<pair<int, string>>st;
        for(auto i: mp)
            st.insert({-1*i.second, i.first});
        
        vector<string>ans;
        auto p = st.begin();
        for(int i=0; i<k; i++)
            ans.push_back((*(p++)).second);
        
        return ans;
    }
    
    
};