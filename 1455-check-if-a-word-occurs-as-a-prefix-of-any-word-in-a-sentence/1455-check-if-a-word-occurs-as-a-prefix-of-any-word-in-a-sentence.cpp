class Solution {
public:
    bool check(string &x,string &y)
    {
        for(int i=0;i<y.length();i++)
        {
            if(x[i]!=y[i])
                return false;
        }
        return true;
    }
    int isPrefixOfWord(string s, string w) {
        vector<pair<string,int>> words;
        string word = "";
        int idx = 1;
        for(auto x:s)
        {
            if(x==' ')
            {
                if(word.length()>=w.length())
                    words.push_back({word,idx});
                idx++;
                word = "";
            }
            else
                word+=x;
        }
        if(word.length()>=w.length())
            words.push_back({word,idx});
        for(auto x:words)
        {
            if(check(x.first,w))
                return x.second;
        }
        return -1;
    }
};