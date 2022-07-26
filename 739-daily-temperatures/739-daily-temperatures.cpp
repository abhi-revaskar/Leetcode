class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            int j = i+1;
            while(j<ans.size() && temperatures[j]<=temperatures[i])
            {
                if(ans[j]==0)
                {
                    j = ans.size();
                }
                else
                    j = j+ans[j];
            }
            // cout<<i<<" "<<j<<endl;
            if(j<ans.size())
                ans[i] = j-i;
        }
        return ans;
    }
};