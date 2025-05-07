#include "BinaryHeap.h"

int BinaryHeap::parent(int i) { return (i - 1) / 2; }
int BinaryHeap::left(int i) { return 2 * i + 1; }
int BinaryHeap::right(int i) { return 2 * i + 2; }

void BinaryHeap::swap(int i, int j)
{
    Element temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Przesuwa element w górę, aby przywrócić własność kopca
void BinaryHeap::heapifyUp(int index)
{
    while (index > 0 && heap[parent(index)].priority < heap[index].priority)
    {
        swap(index, parent(index));
        index = parent(index);
    }
}

// Przesuwa element w dół, aby przywrócić własność kopca
void BinaryHeap::heapifyDown(int index)
{
    int largest = index;
    int l = left(index);
    int r = right(index);

    if (l < size && heap[l].priority > heap[largest].priority)
        largest = l;
    if (r < size && heap[r].priority > heap[largest].priority)
        largest = r;

    if (largest != index)
    {
        swap(index, largest);
        heapifyDown(largest);
    }
}

// Szuka indeksu elementu o danej wartości
int BinaryHeap::findIndex(int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (heap[i].value == value)
            return i;
    }
    return -1; // jeśli nie znaleziono elementu
}

BinaryHeap::BinaryHeap() : heap(nullptr), size(0), capacity(0) {}
BinaryHeap::BinaryHeap(const BinaryHeap &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->heap = new Element[capacity];

    for (int i = 0; i < size; ++i)
    {
        this->heap[i] = other.heap[i];
    }
}

BinaryHeap::~BinaryHeap()
{
    delete[] heap;
}
void BinaryHeap::double_size()
{
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Element *newHeap = new Element[capacity];

    for (int i = 0; i < size; ++i)
    {
        newHeap[i] = heap[i];
    }

    delete[] heap;
    heap = newHeap;
}

// Dodaje nowy element do kopca
void BinaryHeap::insert(int value, int priority)
{
    if (size == capacity)
    {
        double_size();
    }
    heap[size] = {value, priority};
    heapifyUp(size);
    size++;
}

// Usuwa i zwraca element o największym priorytecie
Element BinaryHeap::extract_max()
{
    if (is_empty())
    {
        cout << "Heap is empty!" << endl;
        return {0, 0};
    }
    Element max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return max;
}

// Zwraca element o największym priorytecie
Element BinaryHeap::peek()
{
    if (is_empty())
    {
        cout << "Heap is empty!" << endl;
        return {0, 0};
    }
    return heap[0];
}

// Zmienia priorytet danego elementu
void BinaryHeap::modify_key(int value, int newPriority)
{
    int index = findIndex(value);
    if (index == -1)
    {
        cout << "Element is not found!" << endl;
        return;
    }
    int oldPriority = heap[index].priority;
    heap[index].priority = newPriority;

    if (newPriority > oldPriority)
        heapifyUp(index);
    else
        heapifyDown(index);
}

// Zwraca liczbę elementów
int BinaryHeap::return_size()
{
    return size;
}

// Sprawdza, czy kopiec jest pusty
bool BinaryHeap::is_empty()
{
    return size == 0;
}

// Wypisuje elementy kopca
void BinaryHeap::print() const
{
    cout << "Heap (value:priority): ";
    for (int i = 0; i < size; ++i)
    {
        cout << "(" << heap[i].value << ":" << heap[i].priority << ") ";
    }
    cout << endl;
}
