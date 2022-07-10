class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto x:strs)
        {
            string temp = x;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mp)
        {
            vector<string> grp;
            for(auto y:x.second)
                grp.push_back(y);
            ans.push_back(grp);
        }
        return ans;
    }
};