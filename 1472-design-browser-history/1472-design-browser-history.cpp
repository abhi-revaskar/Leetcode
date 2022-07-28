class BrowserHistory {
public:
    int it;
    vector<string> history;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it=0;
    }
    
    void visit(string url) {
        history.resize(it+1);
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it && steps--)
            it--;
        return history[it];
        
    }
    
    string forward(int steps) {
        while(it<history.size()-1 && steps--)
            it++;
        return history[it];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */