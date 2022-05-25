class Solution {
public:
    void nqueen(vector<vector<string>> &ans,vector<string>& temp,int n,int i,
vector<int>& row,vector<int>& leftD,vector<int>& rightD)
{
  if(i==n)
  {
    ans.push_back(temp);
    return;
  }
  for (int j = 0; j < n; j++)
  {
    if(row[j]==0 && leftD[j-i+n-1]==0 && rightD[i+j]==0)
    {
      temp[i][j]='Q';
      row[j]=1;
      leftD[j-i+n-1]=1;
      rightD[i+j]=1;
      nqueen(ans,temp,n,i+1,row,leftD,rightD);
      temp[i][j]='.';
      row[j]=0;
      leftD[j-i+n-1]=0;
      rightD[i+j]=0;
    }  
  }
}
 vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        for (int i = 0; i < n; i++)
        {
          temp[i]=s;
        }
        vector<int> row(n,0),leftD(2*n-1,0),rightD(2*n-1,0);
        nqueen(ans,temp,n,0,row,leftD,rightD);
        return ans;
    }
};