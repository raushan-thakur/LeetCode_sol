
class BrowserHistory {
class Node{
    public:
    string url;
    Node* next;
    Node* prev;
        
    Node(string url){
        this->url = url;
        this->next = NULL;
        this->prev =NULL;
    }
};
public:
    Node* head;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        head->next = temp;
        temp->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        while(head->prev != NULL && steps>0){
            head = head->prev;
            steps--;
        }
        return head->url;
    }
    
    string forward(int steps) {
        while(head->next != NULL && steps>0){
            head = head->next;
            steps--;
        }
        return head->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */