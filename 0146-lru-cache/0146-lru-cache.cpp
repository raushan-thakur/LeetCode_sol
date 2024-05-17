
class LRUCache {
public:
    class Node{
    public:
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
        
    };
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    unordered_map<int, Node*> mp;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insertNode(int key, int val){
        Node* nextNode = head->next;
        Node* temp = new Node(key, val);
        temp->next = nextNode;
        temp->prev = head;
        nextNode->prev = temp;
        head->next = temp;
    }
    
    void deleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delNext = node->next;
        delprev->next = delNext;
        delNext -> prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* x = mp[key];
            mp.erase(key);
            int res = x->val;
            deleteNode(x);
            insertNode(key, res);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* x = mp[key];
             mp.erase(key);
            deleteNode(x);
        }
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(key, value);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */