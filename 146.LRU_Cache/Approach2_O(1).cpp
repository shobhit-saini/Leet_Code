class LRUCache {
public:
    struct dequeue
    {
        int key;
        int val;
        dequeue* next;
        dequeue* prev;
        dequeue(int k, int v)
        {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };
    map<int, dequeue*>mp;
    int c;
    dequeue* start, *end;
    LRUCache(int capacity) {
        
        c = capacity;
        mp.clear();
        start = new dequeue(0,0);
        end = new dequeue(0,0);
        start->next = end;
        end->prev = start;
    }
    
    void remove(dequeue* temp)
    {
        temp->prev->next = temp->next;
        temp->prev->next->prev = temp->prev;
    }
    void addFront(dequeue* temp)
    {
        temp->next = start->next;
        start->next->prev = temp;
        start->next = temp;
        temp->prev = start;
    }
    int get(int key) {
        
        if(mp.find(key) == mp.end())
            return -1;
        else
        {
            remove(mp[key]);
            addFront(mp[key]);
            return start->next->val;
        }
    }
    
    void put(int key, int value) {
        
        
       if(mp.find(key) != mp.end())
       {
           mp[key]->val = value;
           remove(mp[key]);
           addFront(mp[key]);
       }
        else
        {
            dequeue *temp = new dequeue(key, value);
            if(mp.size() == c)
            {
                mp.erase(end->prev->key);
                remove(end->prev);
                mp[key] = temp;
                addFront(temp);
            }
            else
            {
                mp[key] = temp;
                addFront(temp);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
