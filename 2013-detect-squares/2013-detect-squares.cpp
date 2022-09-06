class DetectSquares {
    unordered_map<int,unordered_multiset<int>> points;
    vector<vector<int>> vert;
public:
    DetectSquares() {
        vert.resize(1001);
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x].insert(y);
        vert[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int ans = 0,x = point[0],y = point[1];
        for(auto y1:vert[x])
        {
            int diff = y-y1;
            if(diff==0)
                continue;
            ans+=(points[x-diff].count(y)*points[x-diff].count(y1));
            ans+=(points[x+diff].count(y)*points[x+diff].count(y1));
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */