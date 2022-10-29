class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n =pt.size();
        vector<pair<int,int>> sq(n);
        for(int i=0;i<n;i++)
        {
            sq[i] = {gt[i],pt[i]};
        }
        sort(begin(sq),end(sq));
        reverse(begin(sq),end(sq));
        int plant = sq[0].second,mx = sq[0].second+sq[0].first;
        for(int i=1;i<n;i++)
        {
            // cout<<plant<<" "<<mx<<endl;
            mx = max(mx,plant+sq[i].second+sq[i].first);
            plant+=sq[i].second;
            // cout<<plant<<" "<<mx<<endl;
        }
        return mx;
    }
};