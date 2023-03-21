class BrowserHistory {
public:
    string history[5555];
    int top;
    int cur;
    BrowserHistory(string homepage) {
        history[0]=homepage;
        top=cur=0;
    }
    
    void visit(string url) {
        history[++cur]=url;
        top=cur;
    }
    
    string back(int steps) {
        cur=max(0,cur-steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur=min(top,cur+steps);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */