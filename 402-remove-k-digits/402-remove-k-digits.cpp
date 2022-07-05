class Solution {
public:
    stack<char> st;
    
    string removeKdigits(string num, int k) {
        string ns = "";
        int kcopy = k;
        if(k==num.size())return "0";
        for(auto i: num) {
            while(!st.empty() && st.top() > i && k>0){
                st.pop();
                k--;
            }
            
            st.push(i);
        }
        
        while(st.size() > num.size() - kcopy){
            st.pop();
        }
        
        while(!st.empty()) {
            ns.push_back(st.top());
            st.pop();
        }
        reverse(ns.begin(), ns.end());
        
        int i=0;
        while(ns[i] =='0')
            i++;
        
        if (ns.substr(i) == "")
            return "0";
        return ns.substr(i);
        
    }
};