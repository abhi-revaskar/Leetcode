class Solution {
public:
    int comp(string s,string t)
{
    if(s.empty() || t.empty())
    return 0;
    int a=0,i=0,j=0;
    while (i<s.length() && j<t.length() && s[i]==t[j])
    {
        a++;
        i++;j++;
    }
    return a;
}
string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        int n=strs.size();
        for (int i = 1; i < n; i++)
        {   
            string t=strs[i];
            if(t.empty()) return "";
            s.resize(comp(s,t));
        }
        return s;

    }
};