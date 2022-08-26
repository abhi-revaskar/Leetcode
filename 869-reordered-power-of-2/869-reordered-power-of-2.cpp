class Solution {
    const long long m = 1e9;
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> s;
        long long p = 1;
        while(p<=m)
        {
            string t = to_string(p);
            sort(t.begin(),t.end());
            // cout<<p<<" "<<t<<endl;
            s.insert(t);
            p*=2;
        }
        // cout<<s.size();
        string t = to_string(n);
        sort(t.begin(),t.end());
        return s.find(t)!=s.end();
    }
};