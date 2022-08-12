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
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};