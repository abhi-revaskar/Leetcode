class Solution {
vector<int> col,leftD,rightD;
public:
    void solve(int i,vector<string> &comb,vector<vector<string>> &ans,int n)
    {
        if(i==n)
        {
            ans.push_back(comb);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(!col[j] && !leftD[j+n-1-i] && !rightD[i+j])
            {
                col[j]=1;
                leftD[j+n-1-i]=1;
                rightD[i+j]=1;
                comb[i][j]='Q';
                solve(i+1,comb,ans,n);
                comb[i][j]='.';
                col[j]=0;
                leftD[j+n-1-i]=0;
                rightD[i+j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        col.resize(n,0),leftD.resize(2*n-1,0),rightD.resize(2*n-1,0);
        vector<string> comb(n,string (n,'.'));
        solve(0,comb,ans,n);
        return ans;
    }
};