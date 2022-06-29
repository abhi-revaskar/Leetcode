class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size(),vector<int> ({INT_MAX,0}));
        sort(people.begin(),people.end());
        for(auto x:people)
            // cout<<x[0]<<" "<<x[1]<<endl;
        int n =people.size();
        for(int j=0;j<people.size();j++)
        {
            auto x = people[j];
            int pos = x[1],seen=0;
            int i=0;
            while(seen<pos)
            {
                if(ans[i][0]>=x[0])
                    seen++;
                i++;
            }
            while(ans[i][0]<x[0])
                i++;
            ans[i]=x;
        }
        return ans;
            
    }
};