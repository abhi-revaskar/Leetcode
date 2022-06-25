class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& b,string w,int it,vector<vector<int>> &vis)
    {
        if(b[i][j]!=w[it])
            return false;
        vis[i][j]=1;
        if(it == w.size()-1)
            return true;
        if(j>0 && vis[i][j-1]==0 && solve(i,j-1,b,w,it+1,vis))
                return true;
        if(j<b[0].size()-1 && vis[i][j+1]==0 && solve(i,j+1,b,w,it+1,vis))
                return true;
        if(i>0 && vis[i-1][j]==0 && solve(i-1,j,b,w,it+1,vis))
                return true;
        if(i<b.size()-1 && vis[i+1][j]==0 && solve(i+1,j,b,w,it+1,vis))
                return true;
        vis[i][j]=0;
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
                    vector<vector<int>> vis(n,vector<int> (m,0));
                    if(solve(i,j,board,w,0,vis))
                        return true;
                }
            }
        }
        return false;
    }
};