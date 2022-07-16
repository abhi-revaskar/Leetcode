class Solution {
public:
    int i=0;
    string decodeString(string s) {
        string ans= "";
        if(i==s.length())
            return ans;
        if(s[i]==']')
        {
            i++;
            return ans;
        }
        if(s[i]>='a' && s[i]<='z')
        {
            ans+=s[i];
            i++;
            return ans+decodeString(s);
        }
        string rep = "";
        while(s[i]!='[')
            rep+=s[i++];
        int count = stoi(rep);
        i++;
        string sub = decodeString(s);
        while(count--)
            ans+=sub;
        return ans+decodeString(s);
    }
};