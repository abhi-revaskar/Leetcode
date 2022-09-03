class Solution {
public:
    void solve(int i,int n,int k,vector<int> &ans)
    {
        if(n==0)
        {
            ans.push_back(i);
            return;
        }
        int last = i%10;
        if(last-k>=0)
            solve(i*10+last-k,n-1,k,ans);
        if(k && last+k<=9)
            solve(i*10+last+k,n-1,k,ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            solve(i,n-1,k,ans);
        }
        return ans;
    }
};