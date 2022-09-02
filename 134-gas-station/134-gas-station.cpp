class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,idx=0;
        for(int i=0;i<gas.size();i++)
            total+=gas[i]-cost[i];
        if(total<0)
            return -1;
        total=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            if(total<0)
            {
                total=0;
                idx=i+1;
            }
        }
        return idx;
    }
};