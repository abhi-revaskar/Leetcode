class Solution {
public:
    void solve(int i,int k,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(ds.size()>k)
            return;
        if(n==0)
        {
            if(ds.size()==k)
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<=9;j++)
        {
            if(j>n)
                return;
            ds.push_back(j);
            solve(j+1,k,n-j,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};