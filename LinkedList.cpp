#include "LinkedList.h"
#include <fstream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList &other)
{
    if (!other.head)
    {
        head = nullptr;
        return;
    }

    head = new Node(other.head->value, other.head->priority);
    Node *current = head;
    Node *nextCurrent = other.head->next;

    while (nextCurrent)
    {
        current->next = new Node(nextCurrent->value, nextCurrent->priority);
        current = current->next;
        nextCurrent = nextCurrent->next;
    }
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
// Wstawia element zgodnie z priorytetem
void LinkedList::insert(int value, int priority)
{
    Node *newNode = new Node(value, priority);
    // Wstawiamy na początek, jeśli lista pusta lub priorytet jest najwyższy
    if (head == nullptr || priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // Szukamy odpowiedniego miejsca w liście
        Node *current = head;
        while (current->next != nullptr && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Usuwa i zwraca element z najwyższym priorytetem
Node *LinkedList::extract_max()
{
    if (is_empty())
    {
        cout << "Queue is empty";
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    temp->next = nullptr; // odłączamy od listy
    return temp;
}

// Zwraca element z najwyższym priorytetem
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

// Zmienia priorytet elementu o podanej wartości
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

// Zwraca liczbę elementów w liście
int LinkedList::return_size()
{
    int size1 = 0;
    Node *current = head;
    while (current != nullptr)
    {
        size1++;
        current = current->next;
    }
    return size1;
}

// Sprawdza, czy lista jest pusta
bool LinkedList::is_empty() const
{
    return head == nullptr;
}

// Wypisuje zawartość listy
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

// Zapisuje dane do pliku
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