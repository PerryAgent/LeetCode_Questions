class Solution {
public:
    map<int, string>m;
    void func(int i, string t, vector<string>& s, string n) {
        for(auto j: m[n[i]-'0']) {
            if(i == n.size()-1)
                s.push_back(t+j);
            else
                func(i+1, t+j, s, n);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        vector<string> s;
        func(0, "", s, digits);
        return s;
        /*

        vector<string>s;
        
        void func(int i, string t){
            for(j in dig[i]){
                if(i==digits.size()-1)
                s.add(t+j); 
                else
                func(i+1, t+j);
            }
            
        }
        int i=0;
        
        func(0, "");
        while(i<digits.size()) {
        if(i==digits.size()-1)
        }
        
        
        */
    }
};