class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[0]>b[0];
    }
    long long minimumMoney(vector<vector<int>>& trans) {
        long long ans=0,sum=0;
        vector<vector<int>> lose,earn;
        for(auto x:trans)
        {
            if(x[1]>=x[0])
                earn.push_back(x);
            else
                lose.push_back(x);
        }
        sort(rbegin(earn),rend(earn));
        sort(lose.begin(),lose.end(),comp);
        for(auto x:lose)
        {
            sum-=x[0];
            ans = min(ans,sum);
            sum+=x[1];
        }
        for(auto x:earn)
        {
            sum-=x[0];
            ans = min(ans,sum);
            sum+=x[1];
        }
        return -ans;
    }
};