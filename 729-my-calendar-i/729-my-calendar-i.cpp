#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;



typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class MyCalendar {
public:
    ordered_set s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(s.empty())
        {
            s.insert({start,end});
            return true;
        }
        int idx = s.order_of_key({start,end});
        if(idx>0)
        {
            auto prev = s.find_by_order(idx-1);
            if(prev->second>start)
                return false;
        }
        if(idx<s.size())
        {
            auto next = s.find_by_order(idx);
            if(next->first<end)
                return false;
        }
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */