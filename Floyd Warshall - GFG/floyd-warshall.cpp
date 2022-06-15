// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dp){
	    for(int i=0;i<dp.size();i++)
	    {
	        for(int j=0;j<dp.size();j++)
	        {
	            for(int k=0;k<dp[0].size();k++)
	            {
	                if(dp[j][i]!=-1 && dp[i][k]!=-1)
	                {
	                    if(dp[j][k]==-1)
	                    dp[j][k]=dp[j][i]+dp[i][k];
	                    else 
	                    dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
	                }
	            }
	        }
	    }
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends