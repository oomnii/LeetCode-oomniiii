class BrowserHistory {
public:
    vector<string> history;
    int curr = 0;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }

    void visit(string url) {
        history.resize(curr + 1);  
        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, curr + steps);
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */