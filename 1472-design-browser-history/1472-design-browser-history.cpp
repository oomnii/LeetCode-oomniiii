class BrowserHistory {
public:
    struct list{
        string data = "";
        list* next = NULL;
        list* prev = NULL;
    };
    
    list* curr = nullptr;

    BrowserHistory(string homepage) {
        list* entry = new list();
        entry->data = homepage;
        curr = entry;
    }
    
    void clearForward(list* node) {
        while (node) {
            list* temp = node;
            node = node->next;
            delete temp;
        }
    }
    
    void visit(string url) {
        clearForward(curr->next);
        list* entry = new list();
        entry->data = url;
        entry->prev = curr;
        curr->next = entry;
        curr = entry;
    }
    
    string back(int steps) {
        while(curr->prev && steps){
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(curr->next && steps){
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */