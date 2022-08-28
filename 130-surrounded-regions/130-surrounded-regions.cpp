class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>> &b)
    {
        if(min(i,j)<0 || i==n || j==m || b[i][j]!='O')
            return;
        b[i][j] = 'N';
        dfs(i+1,j,n,m,b);
        dfs(i-1,j,n,m,b);
        dfs(i,j-1,n,m,b);
        dfs(i,j+1,n,m,b);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(),m= board[0].size();
        for(int i=0;i<n;i++)
        {
            dfs(i,0,n,m,board);
            dfs(i,m-1,n,m,board);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,n,m,board);
            dfs(n-1,i,n,m,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                else if(board[i][j]=='N')
                    board[i][j] = 'O';
            }
        }
    }
};