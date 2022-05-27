class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m)
        return findMedianSortedArrays(nums2,nums1);

        int l=0,h=n;
        int mid;
        int half=(n+m+1)/2;
        while (l<=h)
        {
          mid=(l+h)/2;
          int cut1=mid;
          int cut2=half-mid;

          int l1=cut1==0?INT_MIN:nums1[cut1-1];
          int l2=cut2==0?INT_MIN:nums2[cut2-1];
          int r1=cut1==n?INT_MAX:nums1[cut1];
          int r2=cut2==m?INT_MAX:nums2[cut2];

          if(l1<=r2 && l2<=r1)
          {
            return (n+m)&1?max(l1,l2):((max(l1,l2)+min(r1,r2))/2.0);
          }
          if(l1>r2)
          {
            h=mid-1;
          }
          else
          {
            l=mid+1;
          }

        }
        return -1;
    }
};