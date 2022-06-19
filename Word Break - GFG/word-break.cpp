// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
     int wordBreak(string s, vector<string>& w) {
        unordered_map<string,int> mp;
        for(auto x:w)
        {
            mp[x]=1;
        }
        int dp[s.length()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1; //base condition
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==1) //if a valid segement ends here s[0..j]
                {
                    if(mp.find(s.substr(j,i-j))!=mp.end()) // if the substr s[j..i] is present in the dict
                    {
                        dp[i]=1;
                        break; // found a valid segment ending at this position.
                    }
                }
            }
        }
        return dp[s.length()];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends