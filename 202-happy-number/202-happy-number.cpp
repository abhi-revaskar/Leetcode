class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        unordered_set<string> set;
        set.insert(s);
        while(s!="1")
        {
            int newno = 0;
            for(auto x:s)
                newno+=(x-'0')*(x-'0');
            s = to_string(newno);
            if(set.count(s))
                return false;
            set.insert(s);
        }
        return true;
    }
};