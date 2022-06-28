class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        unordered_set<int> set;
        int ans = 0,freq=1;
        char prev = s[0];
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==prev)
                freq++;
            else
            {
                while(set.find(freq)!=set.end())
                {
                    freq--;
                    ans++;
                }
                if(freq!=0)
                set.insert(freq);
                freq=1;
                prev = s[i];
            }
        }
        while(set.find(freq)!=set.end())
        {
            freq--;
            ans++;
        }
        return ans;
    }
};