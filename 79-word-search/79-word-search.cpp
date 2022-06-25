class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& b,string w)
    {
        if(w.size()==0)
            return true;
        
        if(i<0 || j<0 || i==b.size() || j==b[0].size())
            return false;
        
        
        if(b[i][j]!=w[0])
            return false;
        
        string s = w.substr(1);
        char c = b[i][j];
        b[i][j]='#';
        if(solve(i,j-1,b,s))
            return true;
        if(solve(i,j+1,b,s))
            return true;
        if(solve(i-1,j,b,s))
            return true;
        if(solve(i+1,j,b,s))
            return true;
        
        b[i][j]=c;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string w) {
        int n = board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==w[0])
                {
                    if(solve(i,j,board,w))
                        return true;
                }
            }
        }
        return false;
    }
};