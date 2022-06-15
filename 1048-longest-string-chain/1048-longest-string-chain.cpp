class Solution {
public:
    static bool comp(string i,string j)
    {
        return i.length()<j.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<int> idx(1001,-1);
        for(int i=0;i<words.size();i++)
        {
            idx[words[i].length()]=i;
        }
        vector<int> dp(1001,1);
        int ans = 1;
        for(int i=1;i<words.size();i++)
        {
            if(idx[words[i].length()-1]>=0)
            {
                int id = idx[words[i].length()-1];
                for(int j=id;j>idx[words[i].length()-2];j--)
                {
                    string small = words[j],large = words[i];
                    for(int k=0;k<large.length();k++)
                    {
                        string t = large;
                        t.erase(k,1);
                        if(t==small)
                        {
                            dp[i] = max(dp[i],dp[j]+1);
                            ans = max(ans,dp[i]);
                            break;
                        }
                    }
                }
            }
            else 
            {
                dp[i]=1;
            }
        }
        // cout<<dp[i]<<" "<<idx[words[i].length()]<<endl;
        return ans;
    }
};