// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> final(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        int ans=0,ed = 0;
        for(auto x:adj[0])
        {
            q.push({x[1],x[0]});
        }
        final[0]=1;
        while(ed != V-1)
        {
            auto t = q.top();
            if(final[t.second])
            {
                q.pop();
                continue;
            }
            // cout<<t.first<<" "<<t.second<<endl;
            final[t.second] =1;
            ans+=t.first;
            ed++;
            q.pop();
            for(auto x:adj[t.second])
            {
                if(!final[x[0]])
                {
                    q.push({x[1],x[0]});
                }
            }
            
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends