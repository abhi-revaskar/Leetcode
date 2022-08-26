class Solution {
public:
    bool solve(int i,int j,int n,int m,int k,vector<vector<char>>& board,string &w)
    {
        if(k==w.size())
            return true;
        if(min(i,j)<0 || i==n || j==m || board[i][j]!=w[k])
            return false;
        char c = board[i][j];
        board[i][j] = '#';
        if(solve(i+1,j,n,m,k+1,board,w))
            return true;
        if(solve(i-1,j,n,m,k+1,board,w))
            return true;
        if(solve(i,j+1,n,m,k+1,board,w))
            return true;
        if(solve(i,j-1,n,m,k+1,board,w))
            return true;
        board[i][j] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && solve(i,j,n,m,0,board,word))
                    return true;
            }
        }
        return false;
    }
};