class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0,currmax=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                time+=min(currmax,neededTime[i]);
                currmax = max(currmax,neededTime[i]);
            }
            else
                currmax=neededTime[i];
        }
        return time;
    }
};