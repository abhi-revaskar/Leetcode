class Solution {
    int mod =1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long> mp;
        sort(arr.begin(),arr.end());
        long long ans = 0;
        for(auto x:arr)
            mp[x]=1;
        for(int i=1;i<arr.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && mp[arr[i]/arr[j]])           
                {
                    long long m1 = arr[j], m2 = arr[i]/arr[j];
                    mp[arr[i]]+=(mp[m1]*mp[m2])%mod;
                }
            }
        }
        for(auto x:arr)
            ans+=mp[x]%mod;
        return ans%mod;
    }
};