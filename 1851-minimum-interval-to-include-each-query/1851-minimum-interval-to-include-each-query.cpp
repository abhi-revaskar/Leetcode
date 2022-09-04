class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ints, vector<int>& queries) {
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++)
            q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        sort(ints.begin(),ints.end());
        vector<int> ans(q.size());
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int j=0;j<q.size();j++)
        {
            while(i<ints.size() && ints[i][0]<=q[j][0])
            {
                pq.push({ints[i][1]-ints[i][0]+1,ints[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().second<q[j][0])
                pq.pop();
            if(pq.empty())
                ans[q[j][1]] = -1;
            else
                ans[q[j][1]] = pq.top().first;
        }
        return ans;
    }
};