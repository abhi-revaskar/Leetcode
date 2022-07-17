class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries)
        {
            int k=x[0],trim = x[1];
            vector<pair<string,int>> pq;
            int n = nums[0].size();
            for(int i=0;i<nums.size();i++)
            {
                // cout<<n-k<<endl;
                pq.push_back({nums[i].substr(n-trim),i});
            }
            sort(pq.begin(),pq.end());
            ans.push_back(pq[k-1].second);
        }
        return ans;
    }
};