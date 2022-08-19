class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,multiset<int>> mp;
        for(auto x:nums)
        {
            // cout<<x<<endl;
            if(mp[x-1].empty())
            {
                // cout<<x-1<<" "<<mp[x-1].size()<<" ";
                mp[x].insert(1);
                // cout<<mp[x].size()<<endl;
            }
            else
            {
                auto it = (mp[x-1].begin());
                mp[x].insert(*it+1);
                mp[x-1].erase(it);
                //check empty
            }
        }
        for(auto x:mp)
        {
            if(!x.second.empty() && *(x.second.begin())<3)
                return false;
        }
        return true;
    }
};