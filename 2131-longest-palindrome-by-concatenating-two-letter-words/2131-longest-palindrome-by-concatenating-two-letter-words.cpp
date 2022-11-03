class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        multiset<string> s;
        int len = 0;
        for(auto &x:words)
        {
            string t = x;
            reverse(begin(t),end(t));
            if(s.count(t))
            {
                len+=4;
                s.erase(s.find(t));
            }
            else
                s.insert(x);
        }
        for(auto &x:s)
        {
            if(x[0]==x[1])
            {
                // cout<<"y";
                len+=2;
                break;
            }
        }
        return len;
    }
};