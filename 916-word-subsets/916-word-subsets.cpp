class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> unimap(26,0);
        vector<string> ans;
        for(auto &x:words2)
        {
            vector<int> temp(26,0);
            for(auto &c:x)
            {
                unimap[c-'a'] = max(unimap[c-'a'],++temp[c-'a']);
            }
        }
        for(auto &x:words1)
        {
            vector<int> temp(26,0);
            for(auto &y:x)
            {
                temp[y-'a']++;
            }
            int f=0;
            for(int i=0;i<26;i++)
            {
                if(temp[i]<unimap[i])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ans.push_back(x);
        }
        return ans;
    }
};