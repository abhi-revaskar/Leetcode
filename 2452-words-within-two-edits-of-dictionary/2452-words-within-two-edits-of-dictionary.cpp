class Solution {
public:
    bool check(string &a,string &b)
    {
        int cnt = 0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                cnt++;
        return cnt<=2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto &x:queries)
        {
            for(auto &y:dictionary)
            {
                if(check(x,y))
                {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};