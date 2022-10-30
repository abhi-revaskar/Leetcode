class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        unordered_map<int,vector<int>> ngeidx;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(st.empty())
                ngeidx[-1].push_back(i);
            else
                ngeidx[st.top()].push_back(i);
            st.push(i);
        }
        vector<int> ans(n,-1);
        set<int> s;
        for(int i=n-1;i>=0;i--)
        {
            for(auto &x:ngeidx[i])
            {
                auto it = s.upper_bound(nums[x]);
                if(it!=s.end())
                    ans[x] = *it;

            }
            auto it = s.upper_bound(nums[i]);
            s.erase(s.begin(),it);
            s.insert(nums[i]);
        }
        return ans;
    }
};