class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set;
        for(auto x:words)
            set.insert(x);
        vector<string> ans;
        for(auto x:words)
        {
            vector<int> valid(x.size()+1,0);
            valid[0]=1;
            for(int i=1;i<=x.size();i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(valid[j] && set.count(x.substr(j,i-j)))
                    {
                        valid[i]=1;
                        if(i==x.size() && j!=0)
                            ans.push_back(x);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};