// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	stack<int> st;
	void dfs(int i,vector<int> &v,vector<int> *adj)
	{
	    v[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!v[x])
	        dfs(x,v,adj);
	    }
	    st.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
// 	    vector<int> v(V,0);
// 	    for(int i=0;i<V;i++)
// 	    {
// 	        if(!v[i])
// 	        dfs(i,v,adj);
// 	    }
// 	    vector<int> ans;
// 	while(!st.empty())
// 	{
// 	    ans.push_back(st.top());
// 	    st.pop();
// 	}
// 	return ans;
    vector<int> deg(V,0),ans,v(V,0);
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        for(auto x:adj[i])
        {
            deg[x]++;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(deg[i]==0)
        {
            q.push(i);
            v[i]=1;
        }
    }
    while(!q.empty())
    {
        int t = q.front();
        ans.push_back(t);
        for(auto x:adj[t])
        {
            deg[x]--;
            if(!v[x] && deg[x]==0)
            {
                q.push(x);
                v[x]=1;
            }
        }
        q.pop();
    }
    for(auto x:ans)
    // cout<<x<<" ";
    return ans;
	}
	
};


// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends