class fn{
    public:
    vector<int> tree,arr;
    fn(vector<int>& nums) {
        arr.resize(nums.size(),0);
        tree.resize(arr.size()+1,0);
        for(int i=0;i<arr.size();i++)
        {
            update(i,nums[i]);
            // cout<<tree[i]<<endl;
        }
    }
    
    void update(int index, int val) {
        int add = val-arr[index];
        arr[index]=val;
        index++;
        while(index<=arr.size())
        {
            tree[index]+=add;
            index+=index&-index;
        }
        
    }
    int sum(int index)
    {
        index++;
        int ans = 0;
        while(index)
        {
            ans+=tree[index];
            index=index&(index-1);
        }
        return ans;
    }
};
class NumArray {
public:
    fn *obj;
    NumArray(vector<int>& nums) {
        obj=new fn(nums);
    }
    
    void update(int index, int val) {
        obj->update(index,val);
        
    }
    int sumRange(int left, int right) {
        return (obj->sum(right))-(obj->sum(left-1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */