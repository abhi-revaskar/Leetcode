class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> candies(r.size(),1);
        for(int i=1;i<r.size();i++)
        {
            if(r[i]>r[i-1])
                candies[i]=candies[i-1]+1;
        }
        for(int i=r.size()-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
                candies[i]=max(candies[i],candies[i+1]+1);
        }
        int ans = 0;
        for(auto x:candies)
            ans+=x;
        return ans;
    }
};