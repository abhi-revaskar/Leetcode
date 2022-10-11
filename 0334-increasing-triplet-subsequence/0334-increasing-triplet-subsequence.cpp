class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1=INT_MAX,m2 = INT_MAX;
        for(auto &x:nums)
        {
            if(x>m2)
                return true;
            if(x<=m1)
                m1=x;
            else
                m2=x;
        }
        return false;
    }
};