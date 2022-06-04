class Solution {
public:
    pair<int,int> ispal(string s,int i)
{
    pair<int,int> t={0,0},t1,t2;
    int n=s.length();
    int ans1=INT_MIN,l=i-1,r=i+1,ans2=INT_MIN;
    if(n==1)
    return {0,0};
    if(i==0)
    {
        return s[i]==s[i+1]? t={i,i+1}:t={i,i};
    }
    if(i==n-1)
    {
        return s[i]==s[i-1]?t={i-1,i}:t={i,i};
    }
    if(s[i]!= s[i+1] && s[i-1]!= s[i+1])
    {
        return {i,i};
    }
    if(s[l]== s[r])
    {
        ans1=1;
        while (l>=0 && r<n && s[l]== s[r])
        {
            ans1+=2;
            l--;r++;
        }
        t1= {l+1,r-1};
    }
    if(s[i]== s[i+1])
    {
        r=i+1;
        ans2=0;
        while (i>=0 && r<n && s[i]== s[r])
        {
            i--;r++;
            ans2+=2;
        }
        t2= {i+1,r-1};
    }
    return  ans1>ans2?t1:t2;
}
string longestPalindrome(string s) {
    int ans=INT_MIN;
    pair<int,int> idx;
        for (int i = 0; i < s.length(); i++)
        {
            auto t=ispal(s,i);
            // cout<<t.first<<" "<<t.second<<endl;
            if((t.second-t.first)>ans)
            {
                idx=t;
                ans=t.second-t.first;
            }
        }
        return s.substr(idx.first,ans+1);
    }
};