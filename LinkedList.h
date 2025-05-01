#include <iostream>

struct Node
{
    int value;
    int priority;
    Node *next;

    Node(int val, int prio) : value(val), priority(prio), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList();

    ~LinkedList();

    void insert(int value, int priority);
    int extract_max();
    int peek() const;
    bool is_empty() const;
    void modify_key(int value, int new_priority);
    int return_size() const;
    void print() const;
};
