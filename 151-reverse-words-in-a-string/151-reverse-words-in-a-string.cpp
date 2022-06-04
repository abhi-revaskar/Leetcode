class Solution {
public:
    void revword(string &s,int i,int j)
{
    while (i<j)
    {
        swap(s[i],s[j]);
        i++;j--;
    }
}
string reverseWords(string &s) {
    int i=0,j=0,n=s.length();
    while (s[i]==' ')
    {
        i++;
    }
    j=i;
    while (j<n)
    {
        while (j<n-1 && s[j+1]!=' ')
        {
            j++;
        }
        revword(s,i,j);
        j++;
        while (j<n && s[j]==' ')
        {
            j++;
        }
        i=j;
    }
    revword(s,0,n-1);
    i=j=0;
    while (true)
    {
        while (j<n && s[j]==' ')
        {
            j++;
        }
        if(j==n)
        {
            s.resize(i-1);
            break;
        }
        while (j<n && s[j]!=' ')
        {
            s[i++]=s[j++];
        }
        if(j==n) 
        {
            s.resize(i);
            break;
        }
        s[i++]=s[j];
    }
    return s;
}
};