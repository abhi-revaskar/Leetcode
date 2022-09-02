class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int grpsize) {
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        if(hand.size()%grpsize)
            return false;
        for(auto x:hand)
            mp[x]++;
        for(auto x:hand)
        {
            if(mp[x])
            {
                for(int i=x;i<x+grpsize;i++)
                {
                    if(mp[i]==0)
                        return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};