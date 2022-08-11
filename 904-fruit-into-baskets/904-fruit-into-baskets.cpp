class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        unordered_map<int,int> cnt;
        while(j<fruits.size())
        {
            cnt[fruits[j]]++;
            if(cnt.size()>2)
            {
                cnt[fruits[i]]--;
                if(cnt[fruits[i]]==0)
                    cnt.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return j-i;
    }
};