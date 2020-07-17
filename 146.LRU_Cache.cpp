/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
class LRUCache {
public:
    map<int, int>mp1;
    map<int, int>mp2;
    int c;
    int timer = 0;
    LRUCache(int capacity) {
        
        c = capacity;
    }
    
    int get(int key) {
        
        if( mp1.find(key) != mp1.end() )
        {
            mp2[key] = timer;
            timer++;
            return mp1[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if( mp1.find(key) == mp1.end() )
        {
            if( c == 0 )
            {
                int min = INT_MAX, temp;
                map<int, int>:: iterator itr;
                for( itr = mp2.begin(); itr != mp2.end(); itr++ )
                {
                    if( min > itr->second )
                    {
                        min = itr->second;
                        temp = itr->first;
                    }
                }
                mp1.erase(temp);
                mp2.erase(temp);
                c++;
            }
            mp1[key] = value;
            mp2[key] = timer;
            timer++;
            c--;
        }
        else
        {
            mp1[key] = value;
            mp2[key] = timer;
            timer++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
