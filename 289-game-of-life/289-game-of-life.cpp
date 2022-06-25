class Solution {
public:
    unordered_map<int,int> mp1,mp2;
    int count(int i,int j,vector<vector<int>> &b)
    {
        int ans = 0;
        if(i>0)
        {
            ans+=mp1[b[i-1][j]];
            if(j>0)
                ans+=mp1[b[i-1][j-1]];
            if(j<b[0].size()-1)
                ans+=mp1[b[i-1][j+1]];
        }
        if(j>0)
            ans+=mp1[b[i][j-1]];
        if(j<b[0].size()-1)
            ans+=mp1[b[i][j+1]];
        if(i<b.size()-1)
        {
            ans+=mp1[b[i+1][j]];
            if(j>0)
                ans+=mp1[b[i+1][j-1]];
            if(j<b[0].size()-1)
                ans+=mp1[b[i+1][j+1]];
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& b) {
        mp1 = {{0,0},{1,1},{-1,1},{2,0}};
        mp2 = {{0,0},{1,1},{-1,0},{2,1}};
        int n = b.size(),m=b[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt = count(i,j,b);
                if(b[i][j]==1)
                {
                    if(cnt <=1 || cnt >=4)
                        b[i][j]=-1;
                }
                else if(b[i][j]==0)
                    if(cnt==3)
                        b[i][j]=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                b[i][j] = mp2[b[i][j]];
            }
        }
    }
};