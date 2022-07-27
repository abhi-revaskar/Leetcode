class Solution {
public:
    int dp[41][41];
    int solve(int i,int j,vector<int> &arr)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==j)
            return 0;
        if(i+1==j)
            return arr[i]*arr[j];
        int ans = INT_MAX,fmax = INT_MIN,smax = INT_MIN,n=arr.size();
        vector<int> first(arr.size()),second(arr.size());
        for(int k=i;k<=j;k++)
        {            
            first[k] = fmax=max(fmax,arr[k]);
        }
        for(int k=j;k>=i;k--)
        {            
            second[k] = smax=max(smax,arr[k]);
        }
        for(int k=i;k<j;k++)
        {
            int left=solve(i,k,arr);
            int right=solve(k+1,j,arr);
            ans = min(ans,left+right+first[k]*second[k+1]);
            // cout<<k<<" "<<left<<" "<<right<<" "<<first[k]*second[k+1]<<endl;
        }
        // cout<<i<<" "<<j<<ans;
        return dp[i][j] = ans;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr.size()-1,arr);
    }
};