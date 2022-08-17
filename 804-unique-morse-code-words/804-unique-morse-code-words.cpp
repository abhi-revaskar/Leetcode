class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mp{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> ans;
        for(auto word:words)
        {
            string code = "";
            for(auto c:word)
            {
                code+=mp[c-'a'];
            }
            ans.insert(code);
        }
        return ans.size();
    }
};