class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if (n==0)
        {
          if(m&1)
          return nums2[m/2];
          else 
          return double(nums2[(m-1)/2]+nums2[(m-1)/2+1])/2.0;
        }
        if (m==0)
        {
          if(n&1)
          return nums1[n/2];
          else 
          return double(nums1[(n-1)/2]+nums1[(n-1)/2+1])/2.0;
        }
        int half=(n+m+1)/2;;
        int l=max(0,half-m),h=min(half,n),l1,l2,r1,r2;
        int mid;
        while (l<=h)  
        {
          mid=(l+h)/2;
          l1=mid-1;r1=mid;l2=half-mid-1;r2=half-mid;
          if((l1<0?INT_MIN:nums1[l1])<=(r2==m?INT_MAX:nums2[r2]) && (l2<0?INT_MIN:nums2[l2])<=(r1==n?INT_MAX:nums1[r1]))
          {
            break;
          }
          if(l1>=0 && r2<m && nums1[l1]>nums2[r2])
          {
            h=mid-1;
          }
          else
          {
            l=mid+1;
          }
        }
        // cout<<l1<<r1<<l2<<r2<<endl;
        if((n+m)%2==0)
        return double(max((l1<0?INT_MIN:nums1[l1]),(l2<0?INT_MIN:nums2[l2]))+min((r1==n?INT_MAX:nums1[r1]),(r2==m?INT_MAX:nums2[r2])))/2.0;
        else
        return max(l1<0?INT_MIN:nums1[l1],l2<0?INT_MIN:nums2[l2]);
        
    }
};