class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        sort(begin(target),end(target));
        vector<int> odd,even;
        long long ans = 0;
        int i=0,j=0;
        for(auto x:target)
        {
            if(x&1)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        for(auto x:nums)
        {
            if(x&1)
            {
                // cout<<x<<" "<<odd[j]<<endl;
                if(odd[j]>x)
                    ans+=(odd[j]-x)/2;
                j++;
            }
            else
            {
                // cout<<x<<" "<<even[i]<<endl;
                if(even[i]>x)
                    ans+=(even[i]-x)/2;
                i++;
            }
        }
        return ans;
    }
};