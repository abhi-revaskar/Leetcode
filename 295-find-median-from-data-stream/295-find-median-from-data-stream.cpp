class MedianFinder {
public:
    int size;
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    MedianFinder() {
        size=1;
    }
    
    void addNum(int num) {
        if(size&1)
        {
            if(max.empty() || min.top()>=num)
                max.push(num);
            else
            {
                max.push(min.top());
                min.pop();
                min.push(num);
            }
        }
        else
        {
            if(max.top()<=num)
                min.push(num);
            else
            {
                min.push(max.top());
                max.pop();
                max.push(num);
            }
        }
        size++;        
    }
    
    double findMedian() {
        if(!(size&1))
            return max.top();
        return (max.top()+min.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */