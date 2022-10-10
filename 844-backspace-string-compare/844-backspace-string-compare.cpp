class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int c1=0,c2=0,i=s.length()-1,j=t.length()-1;
        while(i>=0 || j>=0)
        {
            // cout<<i<<" "<<j<<endl;
            while(i>=0 && s[i]=='#')
            {
                c1++;i--;
            }
            while(j>=0 && t[j]=='#')
            {
                c2++;j--;
            }
            while(i>=0 && c1 && s[i]!='#')
            {
                c1--;i--;
            }
            while(j>=0 && c2 && t[j]!='#')
            {
                c2--;j--;
            }
            // cout<<i<<" "<<j<<endl;
            if(i<0 && j<0)
                return true;
            if(i<0 && c2==0 && t[j]!='#')
                return false;
            if(j<0 && c1==0 && s[i]!='#')
                return false;
            if(i>=0 && j>=0 && s[i]!='#' && t[j]!='#' && s[i]!=t[j])
                return false;
            if(i>=0 && j>=0 && s[i]!='#' && t[j]!='#' && s[i]==t[j])
            {
                i--;j--;
            }
        }
        if(i<0 && j<0)
            return true;
        if(i<0 || j<0)
            return false;
        return true;
    }
};