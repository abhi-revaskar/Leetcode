class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(auto &x:sentence)
            s.insert(x);
        return int(s.size())==26;
    }
};