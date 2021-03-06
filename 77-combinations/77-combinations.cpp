class Solution {
public:
    void find(int i,vector<int> &ds,vector<vector<int>> &ans,int n,int k)
    {
       if(k==0)
       {
           ans.push_back(ds);
           return;      
       }
        if(i==n+1)
            return;
        find(i+1,ds,ans,n,k);
        ds.push_back(i);
        find(i+1,ds,ans,n,k-1);
        ds.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        find(1,ds,ans,n,k);
        return ans;
    }
};