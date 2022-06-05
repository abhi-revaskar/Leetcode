class Solution {
public:
    void solve(int n,int i,vector<int> &row,vector<int> &ld,vector<int> &rd,int &ans)
{
    if(i==n)
    {
        ans++;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if(row[j]==0 && ld[j+n-1-i]==0 && rd[i+j]==0)
        {
            row[j]=1;ld[j+n-1-i]=1;rd[i+j]=1;
            solve(n,i+1,row,ld,rd,ans);
            row[j]=0;ld[j+n-1-i]=0;rd[i+j]=0;
        }
    }
    
}
int totalNQueens(int n) {
    if(n==1)
    return 1;
    if(n==2 || n==3)
    return 0;
        vector<int> row(n,0),ld(2*n-1,0),rd(2*n-1,0);
        int ans=0;
        solve(n,0,row,ld,rd,ans);
        return ans;
    }
};