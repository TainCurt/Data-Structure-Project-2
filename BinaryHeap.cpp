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

void BinaryHeap::heapifyUp(int index)
{
    while (index > 0 && heap[parent(index)].priority < heap[index].priority)
    {
        swap(index, parent(index));
        index = parent(index);
    }
}

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

int BinaryHeap::findIndex(int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (heap[i].value == value)
            return i;
    }
    return -1;
}

BinaryHeap::BinaryHeap() : heap(nullptr), size(0), capacity(0) {}

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

Element BinaryHeap::peek()
{
    if (is_empty())
    {
        cout << "Heap is empty!" << endl;
        return {0, 0};
    }
    return heap[0];
}

void BinaryHeap::modify_key(int value, int newPriority)
{
    int index = findIndex(value);
    if (index == -1)
    {
        cout << "Element nie istnieje!" << endl;
        return;
    }
    int oldPriority = heap[index].priority;
    heap[index].priority = newPriority;

    if (newPriority > oldPriority)
        heapifyUp(index);
    else
        heapifyDown(index);
}

int BinaryHeap::return_size()
{
    return size;
}

bool BinaryHeap::is_empty()
{
    return size == 0;
}

void BinaryHeap::print() const
{
    cout << "Heap (value:priority): ";
    for (int i = 0; i < size; ++i)
    {
        cout << "(" << heap[i].value << ":" << heap[i].priority << ") ";
    }
    cout << endl;
}
