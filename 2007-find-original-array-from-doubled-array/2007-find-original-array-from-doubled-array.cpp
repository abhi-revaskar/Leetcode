class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(begin(changed),end(changed));
        unordered_map<int,int> fr;
        for(auto x:changed)
            fr[x]++;
        vector<int> ans;
        for(auto x:changed)
        {
            if(fr[x])
            {
                fr[x]--;
                if(!fr[2*x])
                    return {};
                fr[2*x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};