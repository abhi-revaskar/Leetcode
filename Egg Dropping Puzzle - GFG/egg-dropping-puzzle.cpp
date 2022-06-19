// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[101][10001];
    int superEggDrop1(int k, int n) {
        if(dp[k][n]!=-1)
            return dp[k][n];
        if(n==1 || k==1 || n==0)
            return dp[k][n] = n;
        int ans = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int t = 1+max(superEggDrop1(k-1,i-1),superEggDrop1(k,n-i));
            ans=min(ans,t);
        }
        return dp[k][n] = ans;
    }
    int eggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return superEggDrop1(k,n);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends