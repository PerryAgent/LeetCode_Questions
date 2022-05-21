class Solution {
public:
    bool isValid(string s) {
        vector<char> para;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                para.push_back(s[i]);
            if(s[i] == '}') {
                if (!(para.size()))
                    return false;
                char p = para[para.size()-1];
                if (p == '{')
                    para.pop_back();
                else
                    return false;
            } else if(s[i] == ')') {
                if (!(para.size()))
                    return false;
                char p = para[para.size()-1];
                if (p == '(')
                    para.pop_back();
                else
                    return false;
            } else if(s[i] == ']') {
                if (!(para.size()))
                    return false;
                char p = para[para.size()-1];
                if (p == '[')
                    para.pop_back();
                else
                    return false;
            }
            
                
        }
        if(para.size())
                return false;
            return true;
        
    }
};