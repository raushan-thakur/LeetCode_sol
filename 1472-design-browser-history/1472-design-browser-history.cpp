class Node{
    public:
    Node* next;
    Node* back;
    string data;
    
    Node(string data){
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};
class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->back = current;
        current = newNode;
    }
    
    string back(int steps) {
        while(steps--){
            if(current->back) current = current->back;
            else break;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps--){
            if(current->next) current = current->next;
            else break;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */