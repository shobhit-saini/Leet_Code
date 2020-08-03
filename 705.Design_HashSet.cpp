/*
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
*/
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int capacity;
    vector<vector<int>>bucket;
    int size;
    float loadFactor;
    MyHashSet() {
        
        capacity = 100;
        vector<vector<int>>temp(capacity);
        bucket = temp;
        loadFactor = .75f;
        size = 0;
    }
    
    void add(int key) {
        
        int hash;
        if(contains(key))
            return;
        if(loadFactor*capacity == size)
        {
            capacity = capacity*2;
            vector<vector<int>>oldBucket;
            oldBucket = bucket;
            vector<vector<int>>temp(capacity);
            bucket = temp;
            for(int i = 0; i < oldBucket.size(); i++)
            {
                if(oldBucket[i].size() > 0)
                {
                    for(int j = 0; j < oldBucket[i].size(); j++)
                    {
                        hash = oldBucket[i][j]%capacity;
                        bucket[hash].push_back(oldBucket[i][j]);
                    }
                }
            }
        }
        hash = key%capacity;
        bucket[hash].push_back(key);
        size++;
    }
    
    void remove(int key) {
        
        int hash = key%capacity;
        for(int i = 0; i < bucket[hash].size(); i++)
        {
            if(bucket[hash][i] == key)
            {
                bucket[hash].erase(bucket[hash].begin()+i);
                size--;
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        int hash = key%capacity;
        for(int i = 0; i < bucket[hash].size(); i++)
        {
            if(bucket[hash][i] == key)
            {
                return true;
            }
        }
        return false;
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
