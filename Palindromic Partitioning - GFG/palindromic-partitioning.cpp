// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
int solve(string &s,int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    int l=i,h=j,flag=0;
    if(i>=j)
    return 0;
    while(l<h)
    {
        if(s[l]!=s[h])
        {
            flag=1;
            break;
        }
        l++;h--;
    }
    if(!flag)
    return dp[i][j] = 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int t = 1+ solve(s,i,k)+solve(s,k+1,j);
        ans = min(ans,t);
    }
    return dp[i][j]=ans;
}
    int palindromicPartition(string s)
    {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends