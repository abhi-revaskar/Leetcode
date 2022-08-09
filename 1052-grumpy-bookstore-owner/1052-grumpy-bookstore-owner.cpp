class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int mint) {
        int n = cust.size(),ans = 0;
        vector<int> sum(n),norm(n);
        sum[0]=cust[0];
        if(grumpy[0])
            norm[0]=0;
        else 
            norm[0]=cust[0];
        for(int i=1;i<n;i++)
        {
            sum[i] = cust[i]+sum[i-1];
            norm[i] = (grumpy[i]?norm[i-1]:(cust[i]+norm[i-1]));
            // cout<<sum[i]<<" ";
        }
        // for(auto x:norm)
        //     cout<<x<<" ";
        int s = 0,e =0;
        while(e<n)
        {
            if(grumpy[e]==0)
                e++;
            else
            {
                int t = e;
                e = min(e+mint,n);
                while(e<n && grumpy[e]==0)
                    e++;
                int currsum=sum[e-1]-(s>0?sum[s-1]:0);
                int currnorm = (s>0?norm[s-1]:0) + norm[n-1] - (e>0?norm[e-1]:0);
                ans = max(ans,currsum+currnorm);
                s = t+1;
                e = s;
            }
        }
        int currsum=sum[e-1]-(s>0?sum[s-1]:0);
        int currnorm = (s>0?norm[s-1]:0) + norm[n-1] - (e>0?norm[e-1]:0);
        ans = max(ans,currsum+currnorm);
        return ans;
    }
};