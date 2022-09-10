class bit{
    vector<int> ft;
    int n;
    public:
    bit(int _n)
    {
        n = _n+1;
        ft.resize(n,0);
    }
    int sum(int i)
    {
        int ans = 0;
        while(i)
        {
            ans+=ft[i];
            i = i-(i&-i);
        }
        return ans;
    }
    int update(int i,int step)
    {
        int idx=i;
        while(i<n)
        {
            ft[i]+=1;
            i = i+(i&-i);
        }
        // for(auto x:ft)
        //     cout<<x<<" ";
        // cout<<endl;
        int left = sum(step),right = sum(n-1)-sum(step);
        return left == step && right ==0;
    }
};
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        bit* obj = new bit(flips.size());
        int ans = 0,step=1;
        for(auto x:flips)
        {
            ans+=obj->update(x,step);
            step++;
            // cout<<ans<<endl;
        }
        return ans;
    }
};