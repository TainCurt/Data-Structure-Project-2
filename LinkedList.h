#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
    int value;
    int priority;
    Node *next;

    Node(int val, int prio) : value(val), priority(prio), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    LinkedList(const LinkedList &other);
    ~LinkedList();

    void insert(int value, int priority);
    Node *extract_max();
    Node *peek();
    bool is_empty() const;
    void modify_key(int value, int new_priority);
    int return_size();

    void print() const;
    string save_to_file(string path);
};
