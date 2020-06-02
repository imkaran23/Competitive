// https://leetcode.com/problems/online-stock-span

class StockSpanner {
    stack<pair<int,int> > s;
    int result;
public:
    StockSpanner() {}
    
    int next(int price) {
        result = 1;
        while(!s.empty() && s.top().first<=price){
            result += s.top().second ; 
            s.pop();
        }
        s.push(make_pair(price,result));
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */