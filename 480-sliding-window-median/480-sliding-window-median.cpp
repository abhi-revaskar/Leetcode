#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ordered_set s;
        int n = nums.size();
        for(int i=0;i<k;i++)
            s.insert({nums[i],i});
        vector<double> ans;
        double m1 = (s.find_by_order((k-1)/2))->first;
        double m2 = (s.find_by_order((k+1)/2))->first;
        // cout<<m1<<" "<<m2;
        if(k&1)
            ans.push_back(m1);
        else
            ans.push_back((m1+m2)/2);
        int start = 0, end = k;
        while(end<n)
        {
            s.insert({nums[end],end});
            s.erase({nums[start],start});
            double m1 = (s.find_by_order((k-1)/2))->first;
            double m2 = (s.find_by_order((k+1)/2))->first;
            if(k&1)
                ans.push_back(m1);
            else
            ans.push_back((m1+m2)/2);
            end++;start++;
        }
        return ans;
    }
};