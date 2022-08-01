class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<int>> w(n,vector<int>(n,10001));
        for(auto x:edges)
        {
            w[x[0]][x[1]]=x[2];
            w[x[1]][x[0]]=x[2];
        }
        for(int i=0;i<n;i++)
            w[i][i]=0;
        for(int k=0;k<n;k++)
        {
            // cout<<"k: "<<k<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
                    // cout<<w[i][j]<<" ";
                }
                // cout<<endl;
            }
            // cout<<endl;
            
        }
        int ans_node=0,minnbrs=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int nbrs = 0;
            for(auto nodes:w[i])
                if(nodes<=thresh)
                    nbrs++;
            if(nbrs<=minnbrs)
            {
                minnbrs=nbrs;
                ans_node=i;
            }
        }
        return ans_node;
    }
};