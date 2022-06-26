class Solution {
public:
    void solve(vector<int> &ds,vector<vector<int>> &ans,vector<int> &cand,int i,int t)
    {
        if(t==0)
        {
            ans.push_back(ds);
            return;
        }
        if(i == cand.size() || t<0)
            return;
        solve(ds,ans,cand,i+1,t);
        ds.push_back(cand[i]);
        solve(ds,ans,cand,i,t-cand[i]);
        ds.pop_back()            ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(ds,ans,candidates,0,target);
        return ans;
    }
};