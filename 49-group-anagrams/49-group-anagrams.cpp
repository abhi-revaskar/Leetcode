class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto x:strs)
        {
            string temp = "";
            vector<int> freq(26,0);
            for(auto y:x)
                freq[y-'a']++;
            for(int i=0;i<26;i++)
            {
                temp+=string(freq[i],'a'+i);
            }
            mp[temp].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};