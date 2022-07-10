class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0;
        int ans = 0;
        while(r<s.length())
        {
            if(!mp.count(s[r]))
            {
                ans = max(ans,r-l+1);
                mp[s[r]]=r;
                r++;
            }
            else
            {
                if(mp[s[r]]>=l)
                {
                    l=mp[s[r]]+1;
                    mp[s[r]]=r;
                    r++;
                }
                else
                {
                    ans = max(ans,r-l+1);
                    mp[s[r]]=r;
                    r++;
                }
            }
        }
        return ans;
    }
};