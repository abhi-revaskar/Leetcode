​
for(int i=0;i<adj.size();i++)
{
cout<<i<<":";
for(auto x:adj[i])
{
cout<<"["<<x.first<<","<<x.second<<"]";
}
cout<<endl;
}