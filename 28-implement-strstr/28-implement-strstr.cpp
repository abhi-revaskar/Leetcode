class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int n=haystack.size(),m=needle.size();
        if(m>n)
            return -1;
        int j=m-1;
        while(j<n)
        {
            int t=j,i=m-1;
            while(i>=0 && haystack[t]==needle[i])
            {
                t--;i--;
            }
            if(i<0)
                return t+1;
            else
            {
                while(i>=0 && haystack[t]!=needle[i])
                {
                    i--;
                }
                j=t+m-i-1;
            }
        }
        return -1;               
    }
};