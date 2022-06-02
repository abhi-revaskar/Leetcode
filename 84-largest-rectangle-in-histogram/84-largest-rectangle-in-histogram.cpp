class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> rse,lse;
        int n=heights.size();
        vector<int> r(n),l(n);
        for (int i = 0; i < n; i++)
        {
          while(!rse.empty() && heights[rse.top()]>=heights[n-i-1])
          {
            rse.pop();
          }
          if(rse.empty())
          {
            r[n-i-1]=n;
            rse.push(n-i-1);
          }
          else
          {
            r[n-i-1]=rse.top();
            rse.push(n-i-1);
          }
          while(!lse.empty() && heights[lse.top()]>=heights[i])
          {
            lse.pop();
          }
          if(lse.empty())
          {
            l[i]=-1;
            lse.push(i);
          }
          else
          {
            l[i]=lse.top();
            lse.push(i);
          }
        }
        int ans=INT_MIN;
        for (int i = 0; i < n; i++)
        {
          ans=max(ans,(r[i]-l[i]-1)*heights[i]);
        }
        return ans;
    }
};