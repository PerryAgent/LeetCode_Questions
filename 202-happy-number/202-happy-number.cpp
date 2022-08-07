class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>num;
        if(n==1) return true;
        bool flag = false;
        while(n!=1) {
            if(num.find(n)!=num.end()) break;
            num.insert(n);
            int sum = 0;
            while(n>0) {
                int d = n%10;
                sum += d*d;
                n/=10;
            }
            n = sum;
            if(n==1) flag = 1;
        }
        
        return flag;
    }
};