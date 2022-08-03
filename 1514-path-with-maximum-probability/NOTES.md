```
prob[start]=0;
priority_queue<pair<double,int>> pq;
pq.push({0,start});
while(!pq.empty())
{
double w = pq.top().first;
int node = pq.top().second;
pq.pop();
for(auto x:adj[node])
{
if(prob[x.first]<prob[node]+x.second)
{
prob[x.first] = prob[node]+x.second;
pq.push({prob[x.first],x.first});
}
}
}
return prob[end];
```