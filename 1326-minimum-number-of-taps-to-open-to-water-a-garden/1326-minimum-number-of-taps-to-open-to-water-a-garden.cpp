class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> ints;
        for(int i=0;i<ranges.size();i++)
        {
            ints.push_back({max(i-ranges[i],0),min(i+ranges[i],n)});
        }
        sort(ints.begin(),ints.end(),comp);
        // for(auto x:ints)
        //     cout<<x[0]<<" "<<x[1]<<endl;
        int ans = 1;
        int rightmax = ints[0][1];
        int i =1;
        while(i<ints.size())
        {
            int temp = rightmax;
            if(ints[i][0]>rightmax)
                return -1;
            while(i<ranges.size() && ints[i][0]<=rightmax)
            {
                 temp = max(temp,ints[i][1]);
                i++;
            }
            if(temp!=rightmax)
            ans++;
            rightmax = temp;
        }
        if(rightmax<n)
            return -1;
        return ans;
    }
};