class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n,0);
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        prob[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty())
        {
            double w = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x:adj[node])
            {
                if(prob[x.first]<prob[node]*x.second)
                {
                    prob[x.first] = prob[node]*x.second;
                    pq.push({prob[x.first],x.first});
                }
            }
        }
        return prob[end];
    
    }
};