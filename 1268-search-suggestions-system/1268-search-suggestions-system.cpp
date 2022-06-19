class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string w) {
        unordered_map<string,vector<string>> mp;
        sort(products.begin(),products.end());
        for(auto x:products)
        {
            for(int i=1;i<=x.size();i++)
            {
                mp[x.substr(0,i)].push_back(x);
            }
        }
        vector<vector<string>> ans(w.size());
        for(int i=1;i<=w.size();i++)
        {
            for(int j=0;j<min(3UL,mp[w.substr(0,i)].size());j++)
            {
                ans[i-1].push_back(mp[w.substr(0,i)][j]);
            }
        }
        return ans;
    }
};