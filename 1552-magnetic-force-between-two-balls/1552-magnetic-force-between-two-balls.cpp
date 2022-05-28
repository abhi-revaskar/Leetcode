class Solution {
public:
    bool is(vector<int>& position,int c,int mid)
{
  int cow=1;
  int d1=position[0];
  for (int i = 1; i < position.size(); i++)
  {
    if(position[i]-d1>=mid)
    {
      cow++;
      d1=position[i];
    }
  }
  if(cow<c)
  return false;
  else
  return true;
}
int maxDistance(vector<int>& position, int m)
{
  sort(position.begin(),position.end());
  int mn=INT_MAX;
  int n=position.size();
  for (int i = 0; i < n-1; i++)
  {
    mn=min(mn,position[i+1]-position[i]);
  }
  int l=mn,h=position[n-1]-position[0],mid;
  int ans=INT_MIN;
  while (l<=h)
  {
    mid=(l+h)/2;
    if(is(position,m,mid))
    {
      ans=mid;
      l=mid+1;
    }
    else
    {
      h=mid-1;
    }
  }
  return ans;
  
}
};