# LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

- `LRUCache(int capacity)` Initialize the LRU cache with positive size capacity.
- `int get(int key)` Return the value of the key if the key exists, otherwise return -1.
- `void put(int key, int value)` Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions `get` and `put` must each run in `O(1)` average time complexity.

Practice [Link](https://leetcode.com/problems/lru-cache/description/)

## C++ Implementation

```cpp
class Node{
public:
    int value;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};


class LRUCache {
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int capacity;

    void deleteNode(Node* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete(curr);
    }

    void addNode(Node* curr)
    {
        curr->next = head->next;
        curr->prev = head;

        head->next = curr;
        curr->next->prev = curr;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node* curr = mp[key];
        int result = curr->value;

        mp.erase(key);
        deleteNode(curr);

        addNode(new Node(key, result));
        mp[key] = head->next;

        return result;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end())
        {
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == this->capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```


## JAVA Implementation


```java
class Node{
    int key;
    int val;
    Node prev;
    Node next;

    public Node(int key, int val)
    {
        this.key = key;
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}
class LRUCache {
    private int capacity;
    private Map<Integer, Node> cache;
    private Node latest;
    private Node oldest;

    private void addNode(Node curr)
    {
        curr.next = latest.next;
        curr.prev = latest;

        latest.next = curr;
        curr.next.prev = curr;
    }

    private void detachNode(Node curr)
    {
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
    }


    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new HashMap<>();
        this.latest = new Node(-1,-1);
        this.oldest = new Node(-1,-1);
        latest.next = oldest;
        oldest.prev = latest;
    }
    
    public int get(int key) {
        if(!cache.containsKey(key))
            return -1;

        Node curr = cache.get(key);
        int result = curr.val;

        detachNode(curr);

        addNode(curr);
        cache.put(key,curr);

        return result;
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key))
        {
            Node curr = cache.get(key);
            cache.remove(key);
            detachNode(curr);
        }
        if(cache.size()==capacity)
        {
            cache.remove(oldest.prev.key);
            detachNode(oldest.prev);
        }

        Node curr = new Node(key, value);
        addNode(curr);
        cache.put(key, curr);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```