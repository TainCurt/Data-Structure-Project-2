#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// Struktura przechowująca wartość i jej priorytet
struct Element
{
    int value;
    int priority;
};

// Kopiec binarny maksymalny (Binary Max-Heap)
class BinaryHeap
{
private:
    Element *heap; // tablica z elementami kopca
    int size;      // aktualna liczba elementów
    int capacity;  // maksymalna liczba elementów, zanim trzeba zwiększyć rozmiar

    int parent(int i);           // indeks rodzica
    int left(int i);             // indeks lewego dziecka
    int right(int i);            // indeks prawego dziecka
    void swap(int i, int j);     // zamienia dwa elementy miejscami
    void heapifyUp(int index);   // naprawia kopiec po dodaniu elementu
    void heapifyDown(int index); // naprawia kopiec po usunięciu elementu
    int findIndex(int value);    // znajduje indeks elementu o danej wartości

public:
    BinaryHeap();                                // konstruktor domyślny
    BinaryHeap(const BinaryHeap &other);         // konstruktor kopiujący
    ~BinaryHeap();                               // destruktor
    void insert(int value, int priority);        // dodaje element do kopca
    void double_size();                          // podwaja pojemność tablicy
    Element extract_max();                       // usuwa i zwraca element o największym priorytecie
    Element peek();                              // zwraca element o największym priorytecie (bez usuwania)
    void modify_key(int value, int newPriority); // zmienia priorytet danego elementu
    int return_size();                           // zwraca liczbę elementów
    bool is_empty();                             // sprawdza, czy kopiec jest pusty
    void print() const;                          // wypisuje elementy kopca
};
