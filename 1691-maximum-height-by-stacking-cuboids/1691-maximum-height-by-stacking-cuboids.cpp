class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &x:cuboids)
            sort(x.begin(),x.end());
        sort(cuboids.begin(),cuboids.end());
        vector<int> lis(cuboids.size());
        for(int i=0;i<cuboids.size();i++)
            lis[i] = cuboids[i][2];
        int ans = cuboids[0][2];
        for(int i=1;i<cuboids.size();i++)
        {
            int x = cuboids[i][0],y = cuboids[i][1],z = cuboids[i][2];
            for(int j=i-1;j>=0;j--)
            {
                if(cuboids[j][0]<=x && cuboids[j][1]<=y && cuboids[j][2]<=z)
                    lis[i] = max(lis[i],z+lis[j]);
            }
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};