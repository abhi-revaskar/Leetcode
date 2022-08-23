class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a.length()>b.length();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        string t;
        vector<string> ans;
        for(auto x:words)
        {
            if(t.find(x)!=-1)
                ans.push_back(x);
            t+=x+"#";
        }
        return ans;
    }
};