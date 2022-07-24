class Solution {
public:
    bool canload(int &capacity,vector<int> &wt,int &days)
    {
        int d=1,load = 0;
        for(int i=0;i<wt.size();i++)
        {
            if(load+wt[i]<=capacity)
                load+=wt[i];
            else
            {
                load = wt[i];
                d++;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0,high = 0;
        for(auto &x:weights)
        {
            low = max(low,x);
            high+=x;
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canload(mid,weights,days))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};