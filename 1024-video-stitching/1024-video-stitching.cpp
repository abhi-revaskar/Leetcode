class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        for(auto &x:clips)
            x[1]=min(x[1],time);
        sort(clips.begin(),clips.end(),comp);
        // for(auto x:clips)
        //     cout<<x[0]<<" "<<x[1]<<endl;
        if(clips[0][0]!=0)
            return -1;
        int maxend = clips[0][1],ans = 1,i=1;
        while(i<clips.size())
        {
            if(maxend>=time)
                return ans;
            if(clips[i][0]>maxend)
                return -1;
            int t = maxend;
            while(i<clips.size() && clips[i][0]<=maxend)
            {
                t = max(t,clips[i][1]);
                i++;
            }
            if(t!=maxend)
                ans++;
            maxend = t;
        }
        if(maxend<time)
            return -1;
        return ans;
    }
};