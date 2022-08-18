class Solution {
public:
    int num(string n) {
        int m = 0;
        int sg=1;
        int i=0;
        if(n[0]=='-' || n[0] =='+'){
            if(n[0]=='-') sg*=-1;
            i++;
        }
        while(i<n.size()) {
            m = m*10 + (n[i]-'0');
            i++;
        }
        cout << sg*m<<endl;
        return sg*m;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] =="-" || tokens[i] == "*" || tokens[i] == "/") {
                int r2 = s.top();
                s.pop();
                int r1 = s.top();
                s.pop();
                if(tokens[i]=="+")
                    s.push(r1+r2);
                if(tokens[i]=="-")
                    s.push(r1-r2);
                if(tokens[i]=="*")
                    s.push(r1*r2);
                if(tokens[i]=="/")
                    s.push(r1/r2);
                
                
                
            } else {
                s.push(num(tokens[i]));
            }
        }
        
        return s.top();
    }
};