class Solution {
public:
    void find(int i,vector<int> &ds,vector<vector<int>> &ans,int k,int n)
    {
        if(k==ds.size())
        {
            if(n==0)
            {
                ans.push_back(ds);
                return;
            }
            return;
        }
        
        for(int j=i;j<=9;j++)
        {
            ds.push_back(j);
            find(j+1,ds,ans,k,n-j);
            ds.pop_back();
                
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        find(1,ds,ans,k,n);
        return ans;
    }
};