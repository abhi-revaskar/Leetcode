class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> s;
        int ans = 1;
        for(auto x:rolls)
        {
            s.insert(x);
            if(s.size()==k)
            {
                ans++;
                s.clear();
            }
        }
        return ans;
    }
};