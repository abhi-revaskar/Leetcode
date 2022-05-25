class Solution {
public:
    bool canplace(vector<vector<char>>& board,int i,int j,int d)
{
  //check in row
  for (int col = 0; col < 9; col++)
  {
    if(board[i][col]==d+'0')
    return false;
  }
  //check in col
  for (int row = 0; row < 9; row++)
  {
    if(board[row][j]==d+'0')
    return false;
  }
  //check in sub-box
  int subrow=i/3;
  int subcol=j/3;
  for (int row = subrow*3; row < (subrow+1)*3; row++)
  {
    for (int col = subcol*3; col < (subcol+1)*3; col++)
    {
      if(board[row][col]==d+'0')
      return false;
    }
  }
  return true;
  
}
bool solve(vector<vector<char>>& board,int i,int j)
{
  if (i==9)
  return true;
  if(board[i][j]=='.')
  {
    for (int d = 1; d < 10; d++)
    {
      if(canplace(board,i,j,d))
      {
        board[i][j]=d+'0';
        if(j<8)
        {
          if(solve(board,i,j+1))
          return true;
          board[i][j]='.';
        }
        else
        {
          if(solve(board,i+1,0))
          return true;
          board[i][j]='.';
        }
      }
    }
    return false;
    
  }
  else
  {
    if(j<8)
      {
        return solve(board,i,j+1);
      }
      else
      {
        return solve(board,i+1,0);
      }
  }

}
void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};