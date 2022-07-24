class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto &x:nums)
            s.insert(x);
        nums.clear();
        for(auto x:s)
        {
            int bits = 0;
            while(x)
            {
                bits++;
                x=x&(x-1);
            }
            nums.push_back(bits);
        }
        sort(nums.begin(),nums.end());
        long long ans = 0,indi = 0;
        for(auto &x:nums)
        {
            // if(x>=(k+1)/2)
            //     indi++;
            int idx = lower_bound(nums.begin(),nums.end(),k-x)-nums.begin();
            ans+=nums.size()-idx;
            // cout<<ans<<""<<x<<endl;
        }
        return ans;
    }
};