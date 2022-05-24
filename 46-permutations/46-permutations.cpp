class Solution {
public:
    vector<vector<int>> findperm(vector<vector<int>>& ans,vector<int>& ds,vector<int>& a,int i)
{
  int n=a.size();
  if (n==1)
  {
    ds.push_back(a[0]);
    ans.push_back(ds);
    return ans;
  }
  if (i>=n)
  ans.push_back(ds);
  for (int j = i; j < n; j++)
  {
    swap(a[i],a[j]);
    ds.push_back(a[i]);
    findperm(ans,ds,a,i+1);
    swap(a[i],a[j]);
    ds.pop_back();
  }
  return ans;

}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<vector<int>> perms = findperm(ans,ds,nums,0);
        return perms;
    }
};