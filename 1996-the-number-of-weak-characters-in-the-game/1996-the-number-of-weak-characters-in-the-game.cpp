class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        int ans = 0,maxdefense,lastattack,newdef=INT_MIN;
        sort(pro.begin(),pro.end(),comp);
        maxdefense = pro[0][1],lastattack = pro[0][0];
        int i=0;
        while(i<pro.size())
        {
            while(i<pro.size() && pro[i][0]==lastattack)
                i++;
            if(i==pro.size())
                return ans;
            int newgrp = pro[i][0];
            newdef = max(maxdefense,pro[i][1]);
            while(i<pro.size() && pro[i][0]==newgrp)
            {
                if(pro[i][1]<maxdefense)
                    ans++;
                i++;
            }
            if(i==pro.size())
                return ans;
            lastattack = newgrp;
            maxdefense = newdef;
        }
        return ans;
    }
};