// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int *arr,int i,int j,vector<vector<int>> &dp)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==j)
    return dp[i][j]=0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
        ans = min(ans,solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
        return solve(arr,1,N-1,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends