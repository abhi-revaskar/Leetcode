class Solution {
public:
   void findperm(vector<vector<int>>& ans,vector<int>& a,int i)
{
  int n=a.size();
  if (n==1)
  {
    ans.push_back({a[0]});
      return;
  }
  if (i>=n)
  ans.push_back(a);
  for (int j = i; j < n; j++)
  {
    swap(a[i],a[j]);
    findperm(ans,a,i+1);
    swap(a[i],a[j]);//backtrack
  }

}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findperm(ans,nums,0);
        return ans;
    }
};