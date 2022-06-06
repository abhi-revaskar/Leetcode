class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1(500,0),v2(500,0);
        string t="";
        int idx=0;
        for (int i = 0; i < version1.length(); i++)
        {
            if(version1[i]!='.')
            t+=version1[i];
            else
            {
                v1[idx]=(stoi(t));
                idx++;
                t="";
            }
            
        }
        // cout<<t;
        v1[idx]=(stoi(t));
        idx=0;
        t="";
        for (int i = 0; i < version2.length(); i++)
        {
            if(version2[i]!='.')
            t+=version2[i];
            else
            {
                v2[idx]=(stoi(t));
                idx++;
                t="";
            }
        }
        v2[idx]=(stoi(t));
        idx=0;
        while (idx<v1.size() && v1[idx]==v2[idx])
        {
            idx++;
        }
        if(idx==v2.size())
        return 0;
        return v1[idx]>v2[idx]?1:-1;
    }
};