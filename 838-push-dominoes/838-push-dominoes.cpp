class Solution {
public:
    string pushDominoes(string dominoes) {
        int n= dominoes.size();
        vector<int> left(n),right(n);
        int last = 1000000;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R')
                last = i;
            if(dominoes[i]=='L')
                last = 1000000;
            if(dominoes[i]=='.')
                right[i] = abs(last-i);
        }
        last = 1000000;
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='L')
                last = i;
            if(dominoes[i]=='R')
                last = 1000000;
            if(dominoes[i]=='.')
                left[i] = abs(last-i);
        }
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='.')
            {
                if(left[i]>right[i])
                    dominoes[i] = 'R';
                if(left[i]<right[i])
                    dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};