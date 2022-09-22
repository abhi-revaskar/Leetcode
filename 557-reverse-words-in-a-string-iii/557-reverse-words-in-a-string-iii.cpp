class Solution {
public:
    string reverseWords(string s) {
        string ans,word;
        for(auto x:s)
        {
            if(x==' ')
            {
                reverse(word.begin(),word.end());
                ans+=word+' ';
                word = "";
            }
            else
            {
                word+=x;
            }
        }
        reverse(word.begin(),word.end());
        ans+=word;
        return ans;
    }
};