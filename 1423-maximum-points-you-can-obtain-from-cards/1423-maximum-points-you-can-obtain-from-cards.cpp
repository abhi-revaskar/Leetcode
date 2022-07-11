class Solution {
public:
    int maxScore(vector<int>& a,int k) {
        if(k==0)
          return 0;
          k = a.size()-k;
          int total = 0;
          for(auto x:a)
          total+=x;
          int i=0,j=0;
          int subsum=0,ans = INT_MAX;
          while (j<k)
          {
            subsum+=a[j];
            j++;
          }
          while (j<a.size())
          {
            ans = min(ans,subsum);
            subsum+=a[j];
            subsum-=a[i];
            j++;i++;
          }
          ans = min(ans,subsum);
          // cout<<k<<" "<<total<<" "<<ans<<endl;
          return total - ans;
    }
};