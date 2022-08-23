class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a.length()>b.length();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        unordered_set<string> s;
        vector<string> ans;
        for(auto x:words)
        {
            if(s.count(x))
                ans.push_back(x);
            for(int i=0;i<x.length();i++)
            {
                string t = x.substr(i);
                for(int j=1;j<=t.length();j++)
                s.insert(t.substr(0,j));
            }
        }
        return ans;
    }
};