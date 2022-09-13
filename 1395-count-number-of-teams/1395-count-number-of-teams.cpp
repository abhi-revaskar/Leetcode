class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(),ans=0;
        vector<int> less(n,0),more(n,0);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(rating[j]>rating[i])
                {
                    ans+=more[j];
                    more[i]++;
                }
                else if(rating[j]<rating[i])
                {
                    ans+=less[j];
                    less[i]++;
                }
            }
        }
        return ans;
    }
};