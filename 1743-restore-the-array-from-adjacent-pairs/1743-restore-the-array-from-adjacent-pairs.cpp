class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;
        for(auto i: adjacentPairs) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        
        int start;
        for(auto i: mp) {
            if (i.second.size() == 1) {start = i.first; break;}
        }
        
        set<int> added;
        vector<int> ans;
        
        added.insert(start);
        ans.push_back(start);
        
        while(ans.size() != ((adjacentPairs.size()*2 - 2)/2)+2) {
         for(auto i: mp[start])  {
             if (added.find(i) == added.end())
             {
                 start = i;
                 ans.push_back(i);
                 added.insert(i);
                 break;
             }
         } 
        }
        
        return ans;
    }
};