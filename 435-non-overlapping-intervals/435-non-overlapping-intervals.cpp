class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        sort(ints.begin(),ints.end());
        int i=0,ans=0;
        for(int j=1;j<ints.size();j++)
        {
            auto &x = ints[i],&y = ints[j];
            if(x[1]<=y[0])
                i=j;
            else
            {
                ans++;
                if(x[1]>y[1])
                    i=j;
            }
        }
        return ans;
    }
};