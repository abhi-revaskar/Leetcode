class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int n=nums.size();
    for (int i = 0; i < n; i++) // i = window end
    {
        if(!dq.empty() && dq.front()==i-k) dq.pop_front(); //out of window element at front
        while (!dq.empty() && nums[dq.back()]<nums[i]) //elements lesser than the current one
        {
        dq.pop_back();
        }
        dq.push_back(i); //push current element
        if(i>=k-1) // window is valid
            ans.push_back(nums[dq.front()]);

    }
    return ans;
    }
};