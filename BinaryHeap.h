#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

struct Element
{
    int value;
    int priority;
};

class BinaryHeap
{
private:
    Element *heap;
    int size;
    int capacity;

    int parent(int i);
    int left(int i);
    int right(int i);

    void swap(int i, int j);

    void heapifyUp(int index);

    void heapifyDown(int index);

    int findIndex(int value);

public:
    BinaryHeap();
    BinaryHeap(const BinaryHeap &other);
    ~BinaryHeap();

    void insert(int value, int priority);
    void double_size();
    Element extract_max();

    Element peek();
    void modify_key(int value, int newPriority);
    int return_size();

    bool is_empty();
    void print() const;
};
