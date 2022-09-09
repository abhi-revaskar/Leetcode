class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(),pro.end(),comp);
        int ans = 0,maxdef = pro[0][1];
        for(int i=1;i<pro.size();i++)
        {
            if(pro[i][1]<maxdef)
                ans++;
            maxdef = max(maxdef,pro[i][1]);
        }
        return ans;
    }
};