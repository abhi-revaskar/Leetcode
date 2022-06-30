class Solution {
public:
    bool solve(int i,int j,vector<vector<char>> &board,string s)
    {
        if(!s.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j]!=s[0])
            return false;
        char og = board[i][j];
        board[i][j]='#';
        if(solve(i+1,j,board,s.substr(1)) || solve(i-1,j,board,s.substr(1)) || solve(i,j+1,board,s.substr(1)) || solve(i,j-1,board,s.substr(1)))
            return true;
        board[i][j] = og;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(board[i][j]==word[0] && solve(i,j,board,word))
                    return true;
        }
        return false;
    }
};