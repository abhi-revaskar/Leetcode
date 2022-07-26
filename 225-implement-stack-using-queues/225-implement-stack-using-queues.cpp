class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int pops = q.size()-1;
        while(pops--)
        {
            q.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        int pops = q.size()-1;
        while(pops--)
        {
            q.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        q.push(val);
        return val;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */