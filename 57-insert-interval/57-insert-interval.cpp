class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& add) {
        vector<vector<int>> ans;
        int i=0, n = ints.size();
        while(i<n && ints[i][1]<add[0])
            ans.push_back(ints[i++]);
        if(i==n)
        {
            ans.push_back(add);
            return ans;
        }
        if(add[1]<ints[i][0])
            ans.push_back(add);
        else
        {
            ans.push_back({min(ints[i][0],add[0]),max(ints[i][1],add[1])});
            i++;
        }
        while(i<n)
        {
            auto back = ans.back();
            if(back[1]<ints[i][0])
                ans.push_back(ints[i]);
            else
            {
                ans.pop_back();
                ans.push_back({min(ints[i][0],back[0]),max(ints[i][1],back[1])});
            } 
            i++;
        }
        return ans;
    }
};