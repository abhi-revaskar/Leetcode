class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> uniquefreq;
        vector<int> freqmap(26,0);
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            freqmap[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freqmap[i]==0)
                continue;
            int currfreq = freqmap[i];
            while(uniquefreq.count(currfreq)!=0)
            {
                ans++;
                currfreq--;
            }
            if(currfreq!=0)
                uniquefreq.insert(currfreq);
        }
        return ans;
    }
};