class KthLargest {
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    int K;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        K = k;
        if(n>0)
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i<n-k)
                q1.push(nums[i]);
            else
                q2.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(q2.size()<K)
            q2.push(val);
        else if(val >= q2.top())
        {
            q1.push(q2.top());
            q2.pop();
            q2.push(val);
        }
        else
            q1.push(val);
        return q2.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */