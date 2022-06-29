class Solution {
public:
    void find(int i,vector<int> &ds,vector<vector<int>> &ans,vector<int> &cand,int t)
    {
        if(t<0)
            return;
        if(t==0)
        {
            ans.push_back(ds);
            return ;
        }
        if(i==cand.size())
            return;
        find(i+1,ds,ans,cand,t); //dont pick and move
        ds.push_back(cand[i]);
        find(i,ds,ans,cand,t-cand[i]); //pick and stay
        ds.pop_back(); //backtrack
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<int> ds;
        vector<vector<int>> ans;
        find(0,ds,ans,cand,t);
        return ans;
    }
};