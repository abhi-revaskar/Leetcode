class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(auto x:board)
        {
            s.clear();
            for(auto y:x)
            {
                if(s.count(y))
                    return false;
                if(y!='.')
                s.insert(y);
            }
        }
        for(int i=0;i<9;i++)
        {
            s.clear();
            for(int j=0;j<9;j++)
            {
                if(s.count(board[j][i]))
                    return false;
                if(board[j][i]!='.')
                    s.insert(board[j][i]);
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                s.clear();
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(s.count(board[k][l]))
                            return false;
                        if(board[k][l]!='.')
                            s.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};