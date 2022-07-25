class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.length();i++)
        {
            char x = s[i];
            last[x]=i;
        }
        vector<int> ans;
        int end = last[s[0]],start=0;
        for(int i=0;i<s.length();i++)
        {
            if(i==end)
            {
                ans.push_back(i-start+1);
                if(i==s.length()-1)
                    continue;
                end = last[s[i+1]];
                start=i+1;
            }
            else
            {
                end = max(end,last[s[i]]);
            }
            
        }
        return ans;
    }
};