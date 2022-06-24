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
    
            if(top>bot)
                break;
            for(int i=top;i<=bot;i++)
                ans.push_back(a[i][right]);
            right--;
            
            if(right<left)
                break;
            for(int i=right;i>=left;i--)
                ans.push_back(a[bot][i]);
            bot--;
            
            if(top>bot)
                break;
            for(int i=bot;i>=top;i--)
                ans.push_back(a[i][left]);
            left++;
            
            if(right<left)
                break;
            
        }
        return ans;
    }
};