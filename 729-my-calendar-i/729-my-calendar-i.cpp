class MyCalendar {
public:
    vector<vector<int>> lists;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:lists)
        {
            if(x[1]>start && x[0]<end)
                return false;
        }
        lists.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */