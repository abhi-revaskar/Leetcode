class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size(),ans=0;
        vector<vector<int>> mat(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                    mat[i][j] = matrix[i][j]-'0';
                else if(matrix[i][j]=='1')
                    mat[i][j]+=1+mat[i-1][j];
            }
        }
        for(int i = 0;i<n;i++)
        {
            stack<int> st;
            st.push(0);
            for(int j = 1;j<m;j++)
            {
                while(!st.empty() && mat[i][st.top()]>mat[i][j])
                {
                    int h = mat[i][st.top()];
                    st.pop();
                    ans = max(ans,h*(j-(st.empty()?-1:st.top())-1));
                }
                // cout<<i<<" "<<j<<" "<<ans<<",";
                st.push(j);
            }
            while(!st.empty())
            {
                // cout<<st.top()<<endl;
                int h = mat[i][st.top()];
                st.pop();
                ans = max(ans,h*(m-(st.empty()?-1:st.top())-1));
            }
        }
        return ans;
    }
};