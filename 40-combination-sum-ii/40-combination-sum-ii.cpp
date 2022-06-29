class Solution {
public:
    void find(int i,vector<int> &ds,vector<vector<int>> &ans,vector<int> &cand,int t)
    {
        if(t==0)
        {
            ans.push_back(ds);
            return ;
        }
        if(i==cand.size() || t<0)
            return ;
        for(int j=i;j<cand.size();j++)
        {
            if(j>i && cand[j]==cand[j-1])
                continue;
            ds.push_back(cand[j]);
            find(j+1,ds,ans,cand,t-cand[j]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        sort(cand.begin(),cand.end());
        vector<int> ds;
        vector<vector<int>> ans;
        find(0,ds,ans,cand,t);
        return ans;
    }
};