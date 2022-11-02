class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> vis,s;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        for(auto &x:bank)
            s.insert(x);
        int steps=0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string t = q.front();q.pop();
                if(t==end)
                    return steps;
                for(int i=0;i<8;i++)
                {
                    for(auto x:"ACGT")
                    {
                        string nbr=t;
                        nbr[i]=x;
                        if(vis.count(nbr)==0 && s.count(nbr))
                        {
                            vis.insert(nbr);
                            q.push(nbr);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
            
    }
};