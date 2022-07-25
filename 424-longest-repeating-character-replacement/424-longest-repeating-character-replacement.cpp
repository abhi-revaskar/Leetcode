class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,maxf=0,ans = 0;
        unordered_map<char,int> f;
        while(right<s.length())
        {
            f[s[right]]++;
            maxf = max(maxf,f[s[right]]);
            // cout<<s[right]<<" "<<f[s[right]]<<endl;
            if((right-left+1-maxf)<=k)
            {
                // cout<<left<<" "<<right<<" "<<maxf<<endl;
                ans = max(ans,right-left+1);
                right++;
            }
            else
            {
                f[s[right]]--;
                f[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};