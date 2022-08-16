class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26,0);
        for(auto x:s)
            cnt[x-'a']++;
        for(int i=0;i<s.length();i++)
            if(cnt[s[i]-'a']==1)
                return i;
        return -1;
    }
};