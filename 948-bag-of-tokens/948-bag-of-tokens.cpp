class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans = 0,i=0,j=tokens.size()-1,s=0,n = tokens.size();
        while(i<=j)
        {
            while(i<=j && power>=tokens[i])
            {
                power-=tokens[i];
                s++;
                i++;
            }
            ans = max(ans,s);
            if(s==0)
                break;
            while(i<=j && s && power<tokens[i])
            {
                power+=tokens[j];
                s--;
                j--;
            }
        }
        return ans;
    }
};