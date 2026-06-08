#include <unordered_map>

// i'll use a doubly linked list
struct DoublyLinkedNode
{
    int val;
    int key;
    DoublyLinkedNode *next;
    DoublyLinkedNode *prev;

    DoublyLinkedNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {};
};

class LRUCache
{
private:
    std::unordered_map<int, DoublyLinkedNode *> lt;
    size_t capacity;
    DoublyLinkedNode *head; // most recently used
    DoublyLinkedNode *tail; // least recently used

    void removeNode(DoublyLinkedNode *n)
    {
        if (!n)
        {
            return;
        }

        if (n == head && n == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if (n == tail)
        {
            DoublyLinkedNode *newTail = n->prev;
            tail = newTail;
            newTail->next = nullptr;
            n->prev = nullptr;
        }
        else if (n == head)
        {
            DoublyLinkedNode *newHead = n->next;
            head = newHead;
            newHead->prev = nullptr;
            n->next = nullptr;
        }
        else
        {
            DoublyLinkedNode *prevNode = n->prev;
            DoublyLinkedNode *nextNode = n->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            n->next = nullptr;
            n->prev = nullptr;
        }
    }

    void addToHead(DoublyLinkedNode *n)
    {
        if (head)
        {
            DoublyLinkedNode *oldHead = head;
            n->next = oldHead;
            n->prev = nullptr;
            oldHead->prev = n;
        }
        else
        {
            tail = n;
        }
        head = n;
    }

    void updateNode(DoublyLinkedNode *n, int val)
    {
        if (n)
        {
            n->val = val;
        }
    }

public:
    LRUCache(int c) : capacity(c), head(nullptr), tail(nullptr) {};

    int get(int key)
    {
        if (lt.contains(key))
        {
            DoublyLinkedNode *n = lt[key];
            if (head != n)
            {
                removeNode(n);
                addToHead(n);
            }
            return n->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (lt.contains(key))
        {
            DoublyLinkedNode *n = lt[key];
            updateNode(n, value);
            if (head != n)
            {
                removeNode(n);
                addToHead(n);
            }
        }
        else
        {
            DoublyLinkedNode *newNode = new DoublyLinkedNode{key, value};
            addToHead(newNode);
            lt[key] = newNode;

            // evict least used node
            if (lt.size() > capacity)
            {
                DoublyLinkedNode *victim = tail;
                removeNode(victim);
                lt.erase(victim->key);
                delete victim;
            }
        }
    }
};