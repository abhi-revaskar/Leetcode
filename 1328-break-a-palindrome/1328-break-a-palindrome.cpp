class Solution {
public:
    string breakPalindrome(string pal) {
        if(pal.size()==1)
            return "";
        int n = pal.size();
        for(int i=0;i<(n)/2;i++)
        {
            if(pal[i]!='a')
            {
                pal[i] = 'a';
                return pal;
            }
        }
        for(int i=(n+1)/2;i<n;i++)
        {
            if(pal[i]!='a')
            {
                pal[i] = 'a';
                return pal;
            }
        }
        pal[n-1] = 'b';
        return pal;
    }
};