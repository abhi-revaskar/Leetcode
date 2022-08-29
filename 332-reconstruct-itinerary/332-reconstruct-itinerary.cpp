class Solution {
    int n;
    static bool comp(vector<string> &a,vector<string> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    void dfs(string src,unordered_map<string,vector<string>> &mp,vector<string> &ans)
    {
        ans.push_back(src);
        vector<string> temp = ans;
        // unordered_map<string,vector<string>> temp = mp;
        for(int i=0;i<mp[src].size();i++) //use begin
        {
            auto nbr = mp[src][i];
            if(nbr=="")
                continue;
            mp[src][i] = "";
            // auto it = temp[src].begin()+i;
            // temp[src].erase(it);
            dfs(nbr,mp,ans);
            if(ans.size()==n+1)
                return;
            // temp[src].insert(it,nbr);
            mp[src][i] = nbr;
            ans = temp;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        n = tickets.size();
        unordered_map<string,vector<string>> mp;
        sort(tickets.begin(),tickets.end(),comp);
        for(auto x:tickets)
        {
            mp[x[0]].push_back(x[1]);
        }
        dfs("JFK",mp,ans);
        return ans;
    }
};