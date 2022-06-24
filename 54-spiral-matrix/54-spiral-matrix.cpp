class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int n = a.size(),m=a[0].size();
        int top = 0,bot=n-1,left = 0,right =  m-1;
        while(true)
        {
            //right
            for(int i=left;i<=right;i++)
                ans.push_back(a[top][i]);
            top++;
            // cout<<"top:"<<top<<endl;
            if(top>bot || right<left)
                break;
            for(int i=top;i<=bot;i++)
                ans.push_back(a[i][right]);
            right--;
            // cout<<"right:"<<right<<endl;
            if(top>bot || right<left)
                break;
            for(int i=right;i>=left;i--)
                ans.push_back(a[bot][i]);
            bot--;
            // cout<<"bot:"<<bot<<endl;
            if(top>bot || right<left)
                break;
            for(int i=bot;i>=top;i--)
                ans.push_back(a[i][left]);
            left++;
            // cout<<"left:"<<left<<endl;
            if(top>bot || right<left)
                break;
            
        }
        return ans;
    }
};