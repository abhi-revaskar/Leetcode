class Solution {
public:
   bool backspaceCompare(string s, string t) {
  int n=s.length(),m=t.length();
  int p1=n-1,p2=m-1,c1=0,c2=0;
  while (p1>=0 && p2>=0)
  {
    
    if(s[p1]=='#')
    {
      c1++;
      p1--;
    }
    else if(t[p2]=='#')
    {
      c2++;
      p2--;
    }
    else if(!c1 && !c2 && s[p1]!=t[p2])
    return false;
    else if(c1)
    {
      c1--;
      p1--;
    }
    else if(c2)
    {
      c2--;
      p2--;
    }
    else
    {
      c1=max(0,c1-1);
      c2=max(0,c2-1);
      p1--;
      p2--;
    }
  }

  while (p1>=0)
  {
    if(c1<0)
    return false;
    
    if(s[p1]=='#')
    c1++;
    else
    c1--;
    p1--;
  }
  while (p2>=0)
  {
    if(c1<0)
    return false;
    
    if(t[p2]=='#')
    c2++;
    else
    c2--;
    p2--;
  }
  if(c1<0 || c2<0)
  return false;
  return true;
  }
};