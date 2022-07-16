class Solution {
public:
    void dfs2(int i,int j,vector<vector<char>> &board)
    {
        if(min(i,j)<0 || i==board.size() || j==board[0].size() || board[i][j]!='O')
            return;
        board[i][j] = 'X';
        dfs2(i+1,j,board);
        dfs2(i-1,j,board);
        dfs2(i,j+1,board);
        dfs2(i,j-1,board);
    }
    void dfs(int i,int j,vector<vector<char>> &board)
    {
        if(min(i,j)<0 || i==board.size() || j==board[0].size() || board[i][j]!='O')
            return;
        board[i][j] = 'N';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && min(i,j)==0 || i==m-1 || j==n-1)
                {
                    dfs(i,j,board);
                }
                    
            }
        }
        // print(board);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    dfs2(i,j,board);
                }
                    
            }
        }
        // print(board);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='N')
                {
                    board[i][j]='O';
                }
                    
            }
        }
    }
};