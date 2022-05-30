class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>,greater<int>> q2;
    int c=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        c++;
        if(c==1)
            q1.push(num);
        else if( q1.top()>num)
        {
            q1.push(num);
            if((c&1 && q1.size()>q2.size()+1) || (c%2==0 && q1.size()>q2.size()))
            {
                q2.push(q1.top());
                q1.pop();
            }
        }
        else
        {
            q2.push(num);
            if((c&1 && q1.size()<q2.size()+1) || (c%2==0 && q1.size()<q2.size()))
            {
                q1.push(q2.top());
                q2.pop();
            }
        }
            
    }
    
    double findMedian() {
        if(c&1)
            return q1.top();
        else
            return (q1.top()+q2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */