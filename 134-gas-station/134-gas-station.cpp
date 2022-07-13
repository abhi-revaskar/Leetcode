class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank=0,n=gas.size();
        int ans = -1;
        for(int i=0;i<2*n;i++)
        {
            if(ans==i%n)
                return ans;
            tank+=gas[i%n];
            tank-=cost[i%n];
            if(tank<0)
            {
                ans=-1;
                tank=0;
            }
            else if(ans==-1)
                ans = i;
        }
        return -1;
    }
};