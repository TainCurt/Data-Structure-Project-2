#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(int value, int priority)
{
    Node *newNode = new Node(value, priority);

    if (head == nullptr || priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    size++;
}

int LinkedList::extract_max()
{
    if (is_empty())
    {
        std::cout << "Queue is empty";
        return 0;
    }

    Node *temp = head;
    int maxValue = temp->value;
    head = head->next;
    delete temp;
    size--;
    return maxValue;
}

int LinkedList::peek() const
{
    if (is_empty())
    {
        std::cout << "Queue is empty";
        return 0;
    }

    return head->value;
}

void LinkedList::modify_key(int value, int new_priority)
{
    Node *prev = nullptr;
    Node *current = head;

    while (current != nullptr && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Element not found";
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    size--;

    insert(value, new_priority);
}

int LinkedList::return_size() const
{
    return size;
}

bool LinkedList::is_empty() const
{
    return head == nullptr;
}
void LinkedList::print() const
{
    Node *current = head;
    std::cout << "Queue (value:priority): ";
    while (current != nullptr)
    {
        std::cout << "(" << current->value << ":" << current->priority << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}