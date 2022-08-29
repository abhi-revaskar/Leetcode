class Solution {
public:
    int ladderLength(string root, string end, vector<string>& list) {
        unordered_map<string,vector<char>> mp;
        for(auto x:list)
        {
            for(int i=0;i<x.length();i++)
            {
                string t = x;
                t[i] = '*';
                mp[t].push_back(x[i]);
            }
        }
        unordered_set<string> vis;
        vis.insert(root);
        queue<string> q;
        q.push(root);
        int ans = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string t = q.front();q.pop();
                // cout<<t<<" ";
                if(t==end)
                    return ans;
                for(int i=0;i<t.length();i++)
                {
                    string wild = t;
                    wild[i] = '*';
                    for(auto x:mp[wild])
                    {
                        string nbr = wild;
                        nbr[i] = x;
                        if(vis.count(nbr)==0)
                        {
                            q.push(nbr);
                            vis.insert(nbr);
                        }
                    }
                }
            }
            // cout<<endl;
            ans++;
        }
        return 0;
    }
};