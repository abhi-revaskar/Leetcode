class Solution {
public:
    bool isPossible(int mid,vector<int> &nums,int m)
    {
        int cnt = 1,sum = 0;
        for(auto x:nums)
        {
            if(sum+x<=mid)
                sum+=x;
            else
            {
                cnt++;
                sum=x;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = INT_MIN,high = 0;
        for(auto x:nums)
        {
            low = max(low,x);
            high+=x;
        }
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(mid,nums,m))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};