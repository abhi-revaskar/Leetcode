class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
        return a[0]<b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(),ints.end(),comp);
        vector<vector<int>> ans;
        ans.push_back(ints[0]);
        for(int i=1;i<ints.size();i++)
        {
            auto last = ans.back();
            if(last[1]<ints[i][0])
                ans.push_back(ints[i]);
            else
            {
                ans.pop_back();
                ans.push_back({min(last[0],ints[i][0]),max(last[1],ints[i][1])});
            }
        }
        return ans;
    }
};