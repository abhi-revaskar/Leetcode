class Solution {
public:
    vector<int> manacher_odd(string &s)
{
  int n = s.length();
  s = '$'+s+'*';
  int l = 0,r = 1; //make l = 0
  vector<int> ans(n+1);
  for (int i = 1; i <=n ; i++)
  {
    ans[i] = min(r-i,ans[l+r-i]); // j = l+r-i , i will always be <=r
    //find if ans for i can be increased above curr ans
    while (s[i-ans[i]]==s[i+ans[i]])
    {
      ans[i]++;
    }
    if(i+ans[i]>r)
    {
      r = i+ans[i];
      l = i-ans[i];
    }
  }
  return vector<int>(begin(ans)+1,end(ans));
}
    string longestPalindrome(string s) {
        string t;
        for(auto c:s)
        {
            t+='#';
            t+=c;
        }
        t+='#';
        auto d = manacher_odd(t);
        int n = s.length();
        string ans;
        vector<int> odd(n),even(n);
        for (int i = 0; i < n; i++)
        {
            odd[i] = d[2*i+1]-1;
            even[i] = (d[2*i]-1);
            if(ans.length()<odd[i])
            {
              ans = s.substr(i-odd[i]/2,odd[i]);
            }
            if(ans.length()<even[i])
                ans = s.substr(i-even[i]/2,even[i]);
        }
        return ans;
    }
};