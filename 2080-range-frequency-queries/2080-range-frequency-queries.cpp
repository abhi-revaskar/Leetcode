class RangeFreqQuery {
    unordered_map<int,unordered_map<int,int>> mp;
    unordered_map<int,vector<int>> occ;
    int n;
public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        // build(1,0,arr.size()-1,arr);
        for(int i=0;i<n;i++)
            occ[arr[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        return upper_bound(begin(occ[value]),end(occ[value]),right)-lower_bound(begin(occ[value]),end(occ[value]),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */