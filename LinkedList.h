#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
using namespace std;

// Pojedynczy element listy
class Node
{
public:
    int value;    // wartość elementu
    int priority; // priorytet elementu
    Node *next;   // wskaźnik na następny element

    Node(int val, int prio) : value(val), priority(prio), next(nullptr) {}
};

// Lista jednokierunkowa z priorytetami
class LinkedList
{
private:
    Node *head;

public:
    LinkedList();                                 // konstruktor domyślny
    LinkedList(const LinkedList &other);          // konstruktor kopiujący
    ~LinkedList();                                // destruktor
    void insert(int value, int priority);         // dodaje element
    Node *extract_max();                          // usuwa i zwraca element z najwyższym priorytetem
    Node *peek();                                 // zwraca element z najwyższym priorytetem (bez usuwania)
    bool is_empty() const;                        // sprawdza, czy lista jest pusta
    void modify_key(int value, int new_priority); // zmienia priorytet danego elementu
    int return_size();                            // zwraca liczbę elementów
    void print() const;                           // wypisuje całą listę
    string save_to_file(string path);             // zapisuje dane do pliku
};
