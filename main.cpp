#include <iostream>
#include "Timer.h"
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList que;
    que.insert(10, 2);
    que.insert(15, 1);
    que.insert(12, 3);
    que.insert(20, 1);
    que.insert(250, 1);
    que.insert(12, 1);
    que.insert(50, 1);
    que.insert(20, 4);

    que.print();

    que.extract_max();
    que.print();

    cout << que.peek() << endl;
    cout << que.return_size() << endl;
    ;
    que.modify_key(12, 10);
    que.print();
}