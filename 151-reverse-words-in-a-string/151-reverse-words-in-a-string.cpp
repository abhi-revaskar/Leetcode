class Solution {
public:
    string reverseWords(string s) {
        string w = "";
        string ss = "";
        for(auto x:s)
        {
            if(x!=' ')
                w+=x;
            else if(!w.empty())
            {
                reverse(w.begin(),w.end());
                ss+=w+' ';
                w="";
            }
        }
        if(!w.empty())
        {
            reverse(w.begin(),w.end());
            ss+=w;
        }
        if(ss.back()==' ')
            ss.erase(ss.length()-1);
        reverse(ss.begin(),ss.end());
        return ss;
    }
};