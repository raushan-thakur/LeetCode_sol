class Node{
    public:
    string url;
    Node* prev;
    Node* next;
};
class BrowserHistory {  
    public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr =new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev!= NULL){
            curr=curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next!= NULL){
            curr=curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */