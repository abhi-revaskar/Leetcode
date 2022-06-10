class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.empty())
      return 0;
      int ans=1;
      unordered_map<char,int> mp;
      int i=0,j=1;
      mp[s[i]]=1;
      while (j<s.length())
      {
            // cout<<i<<" "<<j<<" "<<ans;
            if(!mp[s[j]])
            {
                  // cout<<s[j]<<"#"<<endl;
                  ans=max(ans,j-i+1);
                  mp[s[j]]=j+1;
                  j++;
            }
            else
            {
                  // cout<<s[j]<<mp[s[j]]<<endl;
                  int t=mp[s[j]];
                  while (i<t)
                  {
                        mp[s[i]]=0;
                        i++;
                  }
                  // i=mp[s[j]];
                  mp[s[j]]=j+1;
                  j++;
            }
      }
      return ans;
}
  //   int lengthOfLongestSubstring(string s) {
  // if(s.empty())
  // return 0;
  //       int left=0,right=1;
  //       unordered_map<char,int> mp;
  //       mp[s[0]]=0;
  //       int ans=1;
  //       while(right<s.length())
  //       {
  //           if(mp.find(s[right])==mp.end() || mp[s[right]]<left)
  //           {
  //             ans=max(ans,right-left+1);
  //             mp[s[right]]=right;
  //             right++;
  //           }
  //           else
  //           {
  //             left=mp[s[right]]+1;
  //             mp[s[right]]=right;
  //             right++;
  //           }
  //       }
  //       return ans;
  //   }
};