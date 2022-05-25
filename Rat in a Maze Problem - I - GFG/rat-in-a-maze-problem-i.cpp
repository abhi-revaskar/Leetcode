// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>& ans,vector<vector<int>>& v, vector<vector<int>> &m,int n,string s,int i,int j)
{
  if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0)
  return;

  if(v[i][j])
  return;
  if(i==n-1 && j==n-1)
  {
    ans.push_back(s);
    return;
  }
  v[i][j]=1;

  //down
  s+="D";
    solve(ans,v,m,n,s,i+1,j);
    s.pop_back();

  //left
  s+="L";
    solve(ans,v,m,n,s,i,j-1);
    s.pop_back();

  //right
  s+="R";
    solve(ans,v,m,n,s,i,j+1);
    s.pop_back();

  //up
  s+="U";
    solve(ans,v,m,n,s,i-1,j);
    s.pop_back();
  
  v[i][j]=0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int> (n,0));
        solve(ans,visited,m,n,s,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends