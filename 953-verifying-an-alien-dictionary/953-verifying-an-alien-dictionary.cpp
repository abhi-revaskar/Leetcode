class Solution {
    private:
    unordered_map<char,int> pos;
public:
    bool comp(string &s,string &t)
    {
        for(int i=0,j=0;i<s.length() && j<t.length();i++,j++)
        {
            if(pos[s[i]]>pos[t[j]])
                return false;
            else if(pos[s[i]]<pos[t[j]])
                return true;
        }
        return s.length()<=t.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<26;i++)
        {
            pos[order[i]]=i;
        }
        for(int i=1;i<words.size();i++)
        {
            if(!comp(words[i-1],words[i]))
                return false;
        }
        return true;
    }
};