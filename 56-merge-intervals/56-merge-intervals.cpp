class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            auto x = ans.back(),y = intervals[i];
            if(x[1]<y[0])
                ans.push_back(y);
            else
            {
                ans.pop_back();
                ans.push_back({x[0],max(x[1],y[1])});
            }
            
        }
        return ans;
    }
};