#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#define ll long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set s;
        int ans = 0;
        s.insert({nums[0],0});
        for(int i=1;i<nums.size();i++)
        {
            int cnt = s.size()-s.order_of_key({2LL*nums[i]+1,-1});
            ans+=cnt;
            s.insert({nums[i],i});
        }
        return ans;
    }
};