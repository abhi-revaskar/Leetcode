class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end(),comp);
        int last_interval = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<last_interval)
                ans++;
            else
                last_interval = intervals[i][1];
        }
        return ans;
    }
};