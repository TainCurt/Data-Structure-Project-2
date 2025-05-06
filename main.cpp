#include <iostream>
#include "Timer.h"
#include "LinkedList.h"
#include "DataGenerator.h"
#include "BinaryHeap.h"
using namespace std;
int main()
{
    // string folderName = "D:/Programowanie/C++/SD2/DataBase/DataBase100k.txt";
    // string filename;
    // int k = 5000;
    BinaryHeap exampleHeap;
    Timer timer;
    vector<string> tab;
    LinkedList link;
    vector<unique_ptr<BinaryHeap>> copies = prepare_copies(exampleHeap, 10);
}