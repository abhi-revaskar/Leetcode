class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        unordered_map<string,int> mp1;
        int k = w[0].length(),n=w.size();
        if(s.length()<k*n)
            return {};
        for(auto x:w)
            mp1[x]++;
        vector<int> ans;
        for(int i=0;i<=s.size()-n*k;i++)
        {
            int f = 0;
            unordered_map<string,int> mp2;
            for(int j=i;j<i+n*k;j+=k)
            {
                string sub = s.substr(j,k);
                mp2[sub]++;
                if(mp1.count(sub)==0 || mp2[sub]>mp1[sub])
                {
                    f = 1;
                    break;
                }
            }
            if(!f)
                ans.push_back(i);
        }
        return ans;
    }
};