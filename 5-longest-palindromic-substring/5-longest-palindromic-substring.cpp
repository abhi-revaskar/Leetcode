class Solution {
public:
    pair<int,int> palidx(string s,int i,int j)
    {
        pair<int,int> ans{i,j};
        while(i>=0 && j<s.length())
        {
            if(s[i]!=s[j])
                return ans;
            ans.first=i;
            ans.second=j;
            i--;
            j++;
        }
        return ans;
    }
    int palsubstr(string &s,int i,int j){
        int ans = 1;
        while(i>=0 && j<s.length())
        {
            if(s[i]!=s[j])
                return ans;
            ans++;
            i--;
            j++;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int oddidx=0,len1=1,evenidx=0,len2=1;
        for(int i=0;i<s.length();i++)
        {
            int oddlen = palsubstr(s,i,i);
            if(oddlen>len1)
            {
                oddidx=i;
                len1=oddlen;
            }
            int evenlen = palsubstr(s,i,i+1);
            if(evenlen>len2)
            {
                evenidx=i;
                len2 = evenlen;
            }
        }
        pair<int,int> idx;
        string ret = "";
        if(len1>len2)
        {
            idx = palidx(s,oddidx,oddidx);
            return s.substr(idx.first,idx.second-idx.first+1);
        }
        idx = palidx(s,evenidx,evenidx+1);
        return s.substr(idx.first,idx.second-idx.first+1);
        
    }
};