class MyCircularQueue {
public:
    int n,f,b;
    vector<int> q;
    MyCircularQueue(int k) {
        n = k+1;
        f = b =0;
        q.resize(n);
    }
    
    bool enQueue(int value) {
        if(f==((b+1)%n))
            return false;
        q[b] = value;
        b=(b+1)%n;
        return true;
    }
    
    bool deQueue() {
        if(f==b)
            return false;
        f = (f+1)%n;
        return true;
    }
    
    int Front() {
        if(f==b)
            return -1;
        return q[f];
    }
    
    int Rear() {
        if(f==b)
            return -1;
        return q[(b-1+n)%n];
    }
    
    bool isEmpty() {
        return f==b;
    }
    
    bool isFull() {
        return f==((b+1)%n);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */