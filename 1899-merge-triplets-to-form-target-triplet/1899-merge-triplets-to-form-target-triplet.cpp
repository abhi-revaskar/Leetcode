class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int> comp(3,INT_MIN);
        for(auto &x:triplets)
        {
            if(x[0]<=t[0] && x[1]<=t[1] && x[2]<=t[2])
            {
                comp[0] = max(comp[0],x[0]);
                comp[1] = max(comp[1],x[1]);
                comp[2] = max(comp[2],x[2]);
            }
        }
        return comp[0]==t[0] && comp[1] == t[1] && comp[2] == t[2];
    }
};