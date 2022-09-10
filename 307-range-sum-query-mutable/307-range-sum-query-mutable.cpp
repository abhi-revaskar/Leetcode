class NumArray {
    vector<int> bit;
    int n;
    int sum(int i){
        i++;
        int ans = 0;
        while(i)
        {
            ans+=bit[i];
            i = i-(i&(-i));//removing last set bit
        }
        return ans;
    }
public:
    vector<int> A;
    NumArray(vector<int>& nums) {
        A.resize(nums.size(),0);
        bit.resize(nums.size()+1,0);
        n = nums.size()+1;
        for(int i=0;i<nums.size();i++)
            update(i,nums[i]);
    }
    
    void update(int index, int val) {
        val = val-A[index];
        A[index] +=val;
        index++;
        while(index<n)
        {
            bit[index]+=val;
            index = index+(index&(-index));//adding last set bit
        }
    }
    
    int sumRange(int left, int right) {
        int l = 0,r=0;
        while(left)
        {
            l+=bit[left];
            left = left-(left&(-left));
        }
        right++;
        while(right)
        {
            r+=bit[right];
            right = right - (right & (-right));
        }
        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */