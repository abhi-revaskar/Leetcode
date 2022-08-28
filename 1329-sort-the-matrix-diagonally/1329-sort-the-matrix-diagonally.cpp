class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m));
        for(int i=n-1;i>=0;i--)
        {
            int r = i,c=0;
            multiset<int> s;
            while(r<n && c<m)
            {
                s.insert(mat[r][c]);
                r++;c++;
            }
            r = i,c=0;
            while(r<n && c<m)
            {
                ans[r][c] = *(s.begin());
                s.erase(s.begin());
                r++;c++;
            }
        }
        for(int i=1;i<m;i++)
        {
            int r = 0,c=i;
            multiset<int> s;
            while(r<n && c<m)
            {
                s.insert(mat[r][c]);
                r++;c++;
            }
            r = 0,c=i;
            while(r<n && c<m)
            {
                ans[r][c] = *(s.begin());
                s.erase(s.begin());
                r++;c++;
            }
        }
        return ans;
    }
};