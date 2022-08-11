class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        if(m<n)
            return findMedianSortedArrays(nums2,nums1);
        int mid = (m+n+1)/2;
        int low = mid-n , high = mid;
        while(low<=high)
        {
            int k = (low+high)/2;
            int l1 = (k>0?nums1[k-1]:INT_MIN),r1 = (k<m?nums1[k]:INT_MAX);
            int l2 = ((mid-k)>0?nums2[mid-k-1]:INT_MIN),r2 = ((mid-k)<n?nums2[mid-k]:INT_MAX);
            if(l1>r2)
                high = k-1;
            else if(l2>r1)
                low = k+1;
            else
            {
                if((n+m)&1)
                    return max(l1,l2);
                else
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        return -1;
    }
};