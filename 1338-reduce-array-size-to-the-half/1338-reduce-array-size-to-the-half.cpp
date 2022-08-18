class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int n = arr.size();
        for(auto x:arr)
            mp[x]++;
        for(auto x:mp)
            pq.push(x.second);
        int ans = 0,removed=0;
        while(!pq.empty() && removed<n/2)
        {
            ans++;
            removed+=pq.top();
            pq.pop();
        }
        return ans;
    }
};