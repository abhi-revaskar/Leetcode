class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1,0);
        for(auto &x:trust)
        {
            degree[x[1]]++;
            degree[x[0]]--;
        }
        for(int i=1;i<=n;i++)
            if(degree[i]==n-1)
                return i;
        return -1;
    }
};