class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
        sort(meets.begin(),meets.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<int> booked(n,0);
        set<int> unused;
        for(int i=0;i<n;i++)
            unused.insert(i);
        booked[0]++;
        unused.erase(0);
        pq.push({meets[0][1],0});
        for(int i=1;i<meets.size();i++)
        {
            
            
                while(!pq.empty() && pq.top().first<=meets[i][0])
                {
                    unused.insert(pq.top().second);
                    pq.pop();
                }
                if(unused.size())
                {
                    int no = *unused.begin();
                    booked[no]++;
                    pq.push({meets[i][1],no});
                    unused.erase(no);
                }
                else
                {
                    auto top = pq.top();pq.pop();
                    booked[top.second]++;
                    pq.push({top.first-meets[i][0]+meets[i][1],top.second});
                }
        }
        // for(auto x:booked)
        //     cout<<x<<" ";
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(booked[i]>booked[ans])
                ans = i;
        }
        return ans;
    }
};