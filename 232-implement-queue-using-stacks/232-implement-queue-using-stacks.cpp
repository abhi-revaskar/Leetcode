class MyQueue {
public:
    stack<int> in,out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(!out.empty())
        {
            int val = out.top();
            out.pop();
            return val;
        }
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        int val = out.top();
        out.pop();
        return val;
    }
    
    int peek() {
        if(!out.empty())
        {
            return out.top();
        }
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        return out.top();
    }
    
    bool empty() {
        return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */