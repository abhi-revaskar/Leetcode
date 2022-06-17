class Solution {
public:
    
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<int> curr(m+1),prev(m+1);
        for(int j=0;j<=m;j++)
            prev[j]=j;
        for(int i=1;i<n+1;i++)
        {
            curr[0]=i;
            for(int j=1;j<m+1;j++)
            {
                if(w1[i-1]==w2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
            }
            prev=curr;
        }
            return prev[m];
    }
};