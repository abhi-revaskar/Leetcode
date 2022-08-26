class Solution {
public:
    void solve(int i,int sum,vector<int> &ds,vector<vector<int>> &ans,vector<int>& cand)
    {
        if(sum==0)
        {
            ans.push_back(ds);
            return;
        }
        if(sum<0 || i==cand.size())
            return;
        //not pick
        solve(i+1,sum,ds,ans,cand);
        //pick
        ds.push_back(cand[i]);
        solve(i,sum-cand[i],ds,ans,cand);
        ds.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,ds,ans,candidates);
        return ans;
    }
};