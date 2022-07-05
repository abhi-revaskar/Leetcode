class Solution {
public:
    unordered_map<int,int> mp;
    int dp[2001][2001];
    int solve(int pos,int lastpos,vector<int>& stones)
    {
        if(dp[pos][lastpos]!=-1)
            return dp[pos][lastpos];
        if(pos==stones.size()-1)
            return dp[pos][lastpos]= true;
        // cout<<pos<<" "<<lastjump<<endl;
        bool ans = false;
        int lastjump = stones[pos] - stones[lastpos];
        for(int i=lastjump-1;i<=lastjump+1;i++)
        {
            if(i>0 && mp.find(i+stones[pos])!=mp.end())
            {
                ans = ans || solve(mp[i+stones[pos]],pos,stones);
            }
        }
        return dp[pos][lastpos]= ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<stones.size();i++)
            mp[stones[i]]=i;
        return solve(1,0,stones);
    }
};