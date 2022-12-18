// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    class node {
        public:
        int key, value;
        node* next;
        node* prev;
        node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int, node*> hash;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *ptr) {
        ptr->next = head->next;
        ptr->prev = head;
        head->next = ptr;
        ptr->next->prev = ptr;
    }
    void deletenode(node* ptr) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        
        delete ptr;
    }
    int get(int key) {
        if(hash.find(key) == hash.end()) {
            return -1;  
        } 
        node* ptr = hash[key];
        int value = ptr->value;
        deletenode(ptr);
        
        addnode(new node(key, value));
        hash[key] = head->next;
        
        return value;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()) {
            node* ptr = hash[key];
            deletenode(ptr);
            hash.erase(key);
        }
        if(hash.size()==capacity) {
            hash.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        hash[key] = head->next;
    }
    
};