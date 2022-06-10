class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  if(s.empty())
  return 0;
        int left=0,right=1;
        unordered_map<char,int> mp;
        mp[s[0]]=0;
        int ans=1;
        while(right<s.length())
        {
            if(mp.find(s[right])==mp.end() || mp[s[right]]<left)
            {
              ans=max(ans,right-left+1);
              mp[s[right]]=right;
              right++;
            }
            else
            {
              left=mp[s[right]]+1;
              mp[s[right]]=right;
              right++;
            }
        }
        return ans;
    }
};