class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> judge;
        int trusters = 0;
        for(int i=1;i<=n;i++)
            judge.insert(i);
        for(auto &x:trust)
            judge.erase(x[0]);
        if(judge.size()==0)
            return -1;
        int j = *(judge.begin());
        for(auto &x:trust)
            if(x[1]==j)
                trusters++;
        return (trusters==n-1)?j:-1;
    }
};