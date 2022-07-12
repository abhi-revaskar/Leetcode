class Solution {
public:
    bool solve(int i,vector<int> &sides,int target,vector<int> &matchsticks)
    {
        // for(auto x:sides)
        //     cout<<x<<" ";
        // cout<<i<<endl;
        if(i==matchsticks.size())
            return true;
        for(int side=0;side<4;side++)
        {
            if(matchsticks[i]+sides[side]<=target)
            {
                sides[side]+=matchsticks[i];
                if(solve(i+1,sides,target,matchsticks))
                    return true;
                sides[side]-=matchsticks[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4)
            return false;
        int sum=0;
        for(auto x:matchsticks)
            sum+=x;
        if((sum%4)!=0)
            return false;
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end());
        reverse(matchsticks.begin(),matchsticks.end());
        if(matchsticks[0]>(sum/4))
            return false;
        return solve(0,sides,sum/4,matchsticks);
    }
};