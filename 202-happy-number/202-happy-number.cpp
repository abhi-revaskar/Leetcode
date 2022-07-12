class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true)
        {
            if(s.count(n))
                return false;
            s.insert(n);
            int newno=0;
            while(n)
            {
                int dig=n%10;
                n/=10;
                newno+=dig*dig;
            }
            if(newno==1)
                return true;
            n=newno;
        }
    }
};