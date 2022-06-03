class StockSpanner {
public:
    stack<pair<int,int>> st;
    int cnt;
    StockSpanner() {
        cnt=0;
    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top().first<=price)
        {
            st.pop();
        }
        if(st.empty())
        {
            st.push({price,cnt});
            cnt++;
            return cnt;
        }
        else
        {
            ans=cnt - st.top().second;
            st.push({price,cnt});
            cnt++;
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */