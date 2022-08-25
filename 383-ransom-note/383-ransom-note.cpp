class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        for(auto x:magazine)
        {
            freq[x-'a']++;
        }
        for(auto x:ransomNote)
        {
            if(freq[x-'a']==0)
                return false;
            freq[x-'a']--;
        }
        return true;
    }
};