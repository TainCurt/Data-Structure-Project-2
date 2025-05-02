#include <iostream>
#include "Timer.h"
#include "LinkedList.h"
#include "DataGenerator.h"
using namespace std;
int main()
{
    LinkedList data;
    string filename;
    fill_object(&data, "D:/Programowanie/C++/SD2/DataBase/10.txt");
    data.print();
    // int k = 5000;
    // string folderName = "D:/Programowanie/C++/SD2/DataBase/";
    // data.save_to_file("D:/Programowanie/C++/SD2/DataBase/DataBase20k.txt");
    // do
    // {
    //     filename = folderName + "/DataBase" + std::to_string(k / 1000) + "k.txt";
    //     LinkedList data;
    //     fill_object(&data, k);
    //     k += 5000;
    //     data.save_to_file(filename);
    //     data.~LinkedList();
    // } while (k <= 100000);

    // LinkedList que1;
    // fill_object(&que1, 10);
    // vector<unique_ptr<LinkedList>> copies = prepare_copies(que1, 10);
    // cout << "oryginał" << endl;
    // que1.print();
    // cout << "pierwsza kopia" << endl;
    // copies[0]->print();
    // cout << "druga kopia" << endl;
    // copies[1]->print();
    // copies[0]->insert(1, 100);
    // cout << endl;
    // cout << "oryginał" << endl;
    // que1.print();
    // cout << "pierwsza kopia" << endl;
    // copies[0]->print();
    // cout << "druga kopia" << endl;
    // copies[1]->print();
    // LinkedList que1;
    // cout << "obiekt oryginalny" << endl;
    // que1.insert(1, 1);
    // que1.insert(3, 3);
    // que1.insert(2, 2);
    // que1.print();
    // cout << endl;

    // LinkedList que2(que1);
    // cout << "obiekt skopiowany" << endl;
    // que2.print();
    // cout << endl;

    // cout << "zmiana obiektu pierwszego" << endl;
    // que1.insert(4, 4);
    // que1.print();
    // cout << endl;
    // cout << "obiekt skopiowany" << endl;
    // que2.print();
}