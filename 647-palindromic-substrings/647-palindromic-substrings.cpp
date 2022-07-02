class Solution {
public:
   int pals(string s,int i,int j)
   {
       int ans = 0;
       while(i>=0  && j<s.length())
       {
           if(s[i]!=s[j])
               return ans;
           ans++;
           i--;j++;
           
       }
       return ans;
   }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0;i<s.length();i++)
        {
            ans+=pals(s,i,i);
            ans+=pals(s,i,i+1);
        }
        return ans;
    }
};