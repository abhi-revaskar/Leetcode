class Solution {
public:
    bool valid(string &target,int i,string &stamp)
    {
        string replaced = target;
        for(int j=i;j<i+stamp.size();j++)
        {
            if(target[j]!='*' && target[j]!=stamp[j-i])
                return false;
            replaced[j]='*';
        }
        target = replaced;
        return true;
    }
    bool check(string s)
    {
        for(auto &x:s)
            if(x!='*')
                return false;
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(),m = stamp.size(),cnt=0;
        vector<int> ans;
        while(true)
        {
            int f = 0;
            for(int i=0;i<=n-m;)
            {
                if(ans.size()>(n*10))
                    return {};
                if(!check(target.substr(i,m)) && valid(target,i,stamp))
                {
                    // cout<<i<<" "<<target<<endl;
                    ans.push_back(i);
                    f=1;
                    i+=m;
                }
                else
                    i++;
            }
            if(!f)
                break;
        }
        reverse(ans.begin(),ans.end());
        if(check(target))
            return ans;
        return {};
    }
};