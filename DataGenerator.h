#pragma once
#include <numeric>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <random>
#include "LinkedList.h"

using namespace std;

template <class T>
void fill_object(T *obj, int size)
{
    int min = 0;
    int max = 300000;
    int max_for_priorities = size * 10;
    random_device rd1;
    mt19937 gen1(rd1());
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<int> dist1(min, max);
    uniform_int_distribution<int> dist2(min, max_for_priorities);
    for (int i = 0; i < size; i++)
    {
        obj->insert(dist1(gen1), dist2(gen2));
    }
}

template <class T>
void fill_object(T *obj, const string &path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cout << "Failed to open file.";
        return;
    }
    int value, priority;

    while (file >> value >> priority)
    {
        obj->insert(value, priority);
    }
    file.close();
}

template <class T>
vector<unique_ptr<T>> prepare_copies(const T &obj, int number_of_copies)
{
    vector<unique_ptr<T>> result;
    result.reserve(number_of_copies);

    for (int i = 0; i < number_of_copies; ++i)
    {
        result.push_back(make_unique<T>(obj));
    }
    return result;
}
