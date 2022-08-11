class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = -1,second = -1,ans = INT_MIN;
        unordered_map<int,int> idx;
        int l=0,r=0;
        while(r<fruits.size())
        {
            // cout<<l<<","<<r<<" ";
            // cout<<first<<" "<<second<<endl;
            if(idx.count(fruits[r]))
            {
                idx[fruits[r]]=r;
                r++;
            }
            else
            {
                if(first==-1)
                {
                    first = fruits[r];
                    idx[fruits[r]]=r;
                    r++;
                }
                else if(second==-1)
                {
                    second = fruits[r];
                    idx[fruits[r]]=r;
                    r++;
                }
                else
                {
                    ans = max(ans,r-l);   
                    if(idx[second]<idx[first])
                        swap(first,second);
                    l = idx[first]+1;
                    idx.erase(first);
                    first = -1;
                }
                
            }
        }
        ans = max(ans,r-l);
        return ans;
    }
};