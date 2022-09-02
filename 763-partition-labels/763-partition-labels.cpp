class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]] = i;
        int start = 0,end = mp[s[0]];
        vector<int> ans;
        for(int i=0;i<s.length();i++)
        {
            if(i==end)
            {
                ans.push_back(end-start+1);
                if(i==s.length()-1)
                    return ans;
                start = end+1;
                end = mp[s[i+1]];
            }
            else
                end = max(end,mp[s[i]]);
        }
        return ans;
    }
};