class StockSpanner {
public:
    vector<int>span;
    vector<int>stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        int j = span.size()-1;
        while(j>=0) 
        {
            if(price >= span[j]) {
                ans += stock[j];
                j = j - stock[j];
            }
            else break;
        }
        this->span.push_back(price);
        this->stock.push_back(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */