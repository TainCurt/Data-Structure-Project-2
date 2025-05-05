#include <iostream>
#include "Timer.h"
#include "LinkedList.h"
#include "DataGenerator.h"
#include "BinaryHeap.h"
using namespace std;
int main()
{
    BinaryHeap hip;
    LinkedList lis;
    fill_object(&lis, "D:/Programowanie/C++/SD2/DataBase/10.txt");
    fill_object(&hip, "D:/Programowanie/C++/SD2/DataBase/10.txt");
    lis.print();
    cout << endl;
    hip.print();
    cout << lis.return_size() << "to jest return size 1" << endl;

    cout << endl;
    lis.modify_key(123, 300);
    hip.modify_key(123, 180);
    lis.print();
    cout << endl;
    hip.print();
    hip.peek();
    lis.peek();
    lis.extract_max();
    hip.extract_max();
}