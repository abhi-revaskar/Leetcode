class Solution {
public:
    int nthUglyNumber(int n) {
        int k=1;
        unordered_map<long long,int> vis;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        while(true)
        {
            if(k==n)
                return pq.top();
            k++;
            long long top = pq.top();
            pq.pop();
            if(!vis[top*2])
            {
                pq.push(top*2);
                vis[top*2]=1;
            }
            if(!vis[top*3])
            {
                pq.push(top*3);
                vis[top*3]=1;
            }
            if(!vis[top*5])
            {
                pq.push(top*5);
                vis[top*5]=1;
            }
        }
        return -1;
    }
};