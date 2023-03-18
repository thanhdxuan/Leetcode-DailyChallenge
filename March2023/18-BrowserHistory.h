class BrowserHistory {
public:
    int curr;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        history.resize(curr + 1);
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr -= steps;
        if (curr < 0) {
            curr = 0;
            return history.front();
        }
        return history[curr];
    }
    
    string forward(int steps) {
        curr += steps;
        if (curr >= history.size()) {
            curr = history.size() - 1;
            return history.back();
        }
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * string param_2 = obj.back(steps);
 * string param_3 = obj.forward(steps);
 */
