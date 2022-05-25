class Solution {
public:
    bool canplace(int i,int j,int n,vector<string> temp)
{
  int k=i-1,l=j-1;
  while (k>=0 && l>=0)
  {
    if(temp[k][l]=='Q') //left diagonal
    return false;
    k--;l--;
  }
  k=i-1;
  while (k>=0)
  {
    if(temp[k][j]=='Q') //previous rows
    return false;
    k--;
  }
  k=i-1;l=j+1;
  while (k>=0 && l<n)
  {
    if(temp[k][l]=='Q') //right diagonal
    return false;
    k--;l++;
  }
  return true;
}
void nqueen(vector<vector<string>> &ans,vector<string>& temp,int n,int i)
{
  if(i==n)
  {
    ans.push_back(temp);
    return;
  }
  for (int j = 0; j < n; j++)
  {
    if(canplace(i,j,n,temp))
    {
      temp[i][j]='Q';
      nqueen(ans,temp,n,i+1);
      temp[i][j]='.';
    }  
  }
}
 vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> temp(n);
        for (int i = 0; i < n; i++)
        {
          temp[i]=s;
        }
        nqueen(ans,temp,n,0);
        return ans;
    }
};