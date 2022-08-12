class Solution {
public:
    bool isPossible(long long mid,vector<int> &piles,int h)
    {
        long long hours = 0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=(piles[i]+mid-1)/mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1,high = 0;
        for(auto x:piles)
        {
            high+=x;
        }
        while(low<=high)
        {
            long long mid = (low+high)/2;
            if(isPossible(mid,piles,h))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};