class Solution {
public:
    int many(vector<int> &p,long long i)
{
      int n =p.size();
      int l=0,r=n-1;
      while (l<=r)
      {
            int mid=(l+r)>>1;
            if((1LL*p[mid])<i)
            l=mid+1;
            else 
            r=mid-1;
      }
      return n-l;
}
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); i++)
        {
            ans[i]=many(potions, (success+spells[i]-1)/spells[i]);
        }
    
    return ans;
    }
};