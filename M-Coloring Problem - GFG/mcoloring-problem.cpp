// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool canpaint(bool graph[101][101],int i,int c,vector<int>& nodes)
{
  for (int j = 0; j < nodes.size(); j++)
  {
    if(graph[i][j]==1 && nodes[j]==c)
    return false;
  }
  return true;
  
}
bool solve(bool graph[101][101],int m,int n,vector<int>& nodes,int i)
{
  if(i==n)
  return true;
  for (int c = 0; c < m; c++)
  {
    if(canpaint(graph,i,c,nodes))
    {
      nodes[i]=c;
      if(solve(graph,m,n,nodes,i+1))
      {
        return true;
      }
      nodes[i]=-1;
    }
  }
  return false;
  

}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> nodes(n,-1);
    return solve(graph,m,n,nodes,0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends