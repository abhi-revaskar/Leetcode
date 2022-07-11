class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(),n=t.length();
        if(s.length()<t.length())
            return "";
        int len = 0,i=0,j=0,ifin=0,jfin=INT_MAX;
        unordered_map<char,int> mp1,mp2;
        for(auto x:t)
            mp1[x]++;
        while(j<m && mp1.count(s[j])==0)
            j++;
        if(j==m)
            return "";
        i=j;
        j++;
        len++;
        if(len==n)
            return t;
        mp2[s[i]]++;
        while(j<m)
        {
            while(j<m && mp1.count(s[j])==0)
                j++;
            if(j==m)
                break;
            mp2[s[j]]++;
            // cout<<s[j]<<" "<<mp2[s[j]]<<" "<<mp1[s[j]]<<endl;
            // cout<<"len b4"<<len<<endl;
            if(mp2[s[j]]<=mp1[s[j]])
                len++;
            // cout<<i<<" "<<j<<" "<<len<<endl;
            while(len==n)
            {
                if((jfin-ifin)>(j-i))
                {
                    jfin=j;
                    ifin=i;
                    // cout<<"fin:"<<ifin<<" "<<jfin<<endl;
                }
                
                mp2[s[i]]--;
                // cout<<"mp2[s[i]]:"<<mp2[s[i]]<<endl;
                if(mp2[s[i]]<mp1[s[i]])
                {
                    len--;
                }
                i++;
                while(i<m && mp1.count(s[i])==0)
                    i++;
                if(i==m)
                    break;
                // cout<<"new:"<<i<<" "<<j<<"len:"<<len<<endl;
            }
            j++;
        }
        // cout<<jfin<<ifin;
        if(jfin==INT_MAX)
            return "";
        return s.substr(ifin,jfin-ifin+1);
    }
};
