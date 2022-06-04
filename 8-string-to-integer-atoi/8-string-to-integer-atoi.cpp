class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        char sign='X';
        int f=0,i=0;
        while (i<s.length() && s[i]==' ')
        {
            i++;
        }
        if(i==s.length() || (s[i]!='-' && s[i]!='+' && (s[i]<'0' || s[i]>'9')))
        return 0;
        if((s[i]=='-' || s[i]=='+') && (i==s.length()-1 || s[i+1]<'0' || s[i+1]>'9'))
        return 0;
        if(s[i]=='-' || s[i]=='+') 
        {
            sign=s[i];
            i++;
        }
        string t="";
        while (i<s.length() && (s[i]>='0' && s[i]<='9'))
        {
            t+=s[i];
            i++;
        }
        i=0;
        while (i<t.length())
        {
            if(ans>INT_MAX || ans < INT_MIN)
            {
                ans=sign=='-'?-ans:ans;
                return max(INT_MIN*1LL,min(INT_MAX*1LL,ans));
            }
             ans=ans*10+t[i]-'0';
             i++;
        }
        ans=sign=='-'?-ans:ans;
        return max(INT_MIN*1LL,min(INT_MAX*1LL,ans));
    }
};