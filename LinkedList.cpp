#include "LinkedList.h"
#include <fstream>

LinkedList::LinkedList() : head(nullptr) {}

// LinkedList::LinkedList(const LinkedList &other)
// {
//     if (!other.head)
//     {
//         head = nullptr;
//         size = 0;
//         return;
//     }

//     head = new Node(other.head->value, other.head->priority);
//     Node *current = head;
//     Node *nextCurrent = other.head->next;

//     while (nextCurrent)
//     {
//         current->next = new Node(nextCurrent->value, nextCurrent->priority);
//         current = current->next;
//         nextCurrent = nextCurrent->next;
//     }
//     size = other.size;
// }

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
}

Node *LinkedList::extract_max()
{
    if (is_empty())
    {
        cout << "Queue is empty";
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    return temp;
}

Node *LinkedList::peek()
{
    Node *max = head;
    if (is_empty())
    {
        cout << "Queue is empty";
        return nullptr;
    }
    return max;
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
        cout << "Element not found";
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

    insert(value, new_priority);
}

int LinkedList::return_size()
{
    int size1;
    Node *current = head;
    while (current != nullptr)
    {
        size1++;
        current = current->next;
    }
    return size1;
}
bool LinkedList::is_empty() const
{
    return head == nullptr;
}
void LinkedList::print() const
{
    Node *current = head;
    cout << "Queue (value:priority): ";
    while (current != nullptr)
    {
        cout << "(" << current->value << ":" << current->priority << ") ";
        current = current->next;
    }
    cout << endl;
}

string LinkedList::save_to_file(string path)
{
    int size = return_size();
    ofstream file(path);
    if (!file.is_open())
    {
        return "Failed to open file.";
    }

    Node *current = head;
    while (current != nullptr)
    {
        file << current->value << ' ' << current->priority << '\n';
        current = current->next;
    }
    file.close();
    return "Data saved successfully."; // Komunikat o sukcesie
}