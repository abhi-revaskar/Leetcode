class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0,n=nums1.size(),m = nums2.size();
        for(int i=0;i<n;i++)
        {
            int tempans=0,maxcnt=0;
            for(int j=0;j<m;j++)
            {
                if(i+j==n)
                    break;
                if(nums1[i+j]!=nums2[j])
                {
                    tempans = max(tempans,maxcnt);
                    maxcnt=0;
                }
                else
                maxcnt++;
            }
            tempans = max(tempans,maxcnt);
            ans = max(ans,tempans);
        }
        for(int i=0;i<m;i++)
        {
            int tempans=0,maxcnt=0;
            for(int j=0;j<n;j++)
            {
                if(i+j==m)
                    break;
                if(nums2[i+j]!=nums1[j])
                {
                    tempans = max(tempans,maxcnt);
                    maxcnt=0;
                }
                else
                maxcnt++;
            }
            tempans = max(tempans,maxcnt);
            ans = max(ans,tempans);
        }
        return ans;
    }
};