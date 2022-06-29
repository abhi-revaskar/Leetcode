class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto x:s)
        {
            if(x>='A' && x<='Z')
                t+=('a'+x-'A');
            if((x>='a' && x<='z') || (x>='0' && x<='9'))
                t+=x;
        }
        for(int i = 0;i<t.length();i++)
        {
            if(t[i]!=t[t.length()-i-1])
                return false;
        }
        return true;
    }
};