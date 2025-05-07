#include <iostream>
#include "Timer.h"
#include "LinkedList.h"
#include "DataGenerator.h"
#include "BinaryHeap.h"
#include <random>
using namespace std;

void showDataStructures()
{
    cout << "Choose a data structure:\n";
    cout << "1. List\n";
    cout << "2. Heap\n";
}
void showInputMethods()
{
    cout << "\nChoose the data input method:\n";
    cout << "1. Generate randomly\n";
    cout << "2. Load from file\n";
}
void showFiles()
{
    cout << "\nChoose a file (1-20):\n";
    cout << "1. 5k           6. 30k          11. 55k          16. 80k \n";
    cout << "2. 10k          7. 35k          12. 60k          17. 85k \n";
    cout << "3. 15k          8. 40k          13. 65k          18. 90k \n";
    cout << "4. 20k          9. 45k          14. 70k          19. 95k \n";
    cout << "5. 25k          10. 50k         15. 75k          20. 100k\n";
}

void showOperations()
{
    cout << "\nChoose an operation to perform:\n";
    cout << "1. Insert()\n";
    cout << "2. Extract-max()\n";
    cout << "3. Peek()\n";
    cout << "4. Modify-key()\n";
    cout << "5. Return-size()\n";
}

int main()
{
    int structureChoice;
    int dataMethod;
    int fileNumber;
    int operationChoice;
    string folderName = "D:/Programowanie/C++/SD2/DataBase/";
    string filename;
    int size;
    int priority;
    int value;

    showDataStructures();
    cin >> structureChoice;

    showInputMethods();
    cin >> dataMethod;
    if (dataMethod == 1)
    {
        cout << "Please, enter what size do you want to test: ";
        cin >> size;
    }

    if (dataMethod == 2)
    {
        showFiles();
        cin >> fileNumber;
        vector<int> sizes = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
        if (fileNumber < 1 || fileNumber > 20)
        {
            cout << "Invalid file number.\n";
            return 1;
        }
        filename = folderName + "/DataBase" + to_string(sizes[fileNumber - 1]) + "k.txt";
    }

    showOperations();
    cin >> operationChoice;
    if (operationChoice == 1 || operationChoice == 4)
    {
        cout << "Enter value: ";
        cin >> value;
        cout << "Enter priority: ";
        cin >> priority;
    }

    switch (structureChoice)
    {
    case 1:
    {
        vector<unique_ptr<LinkedList>> copies;
        LinkedList list;
        if (dataMethod == 1)
        {
            fill_object(&list, size);
            copies = prepare_copies(list, 100);
        }
        else
        {
            fill_object(&list, filename);
            copies = prepare_copies(list, 100);
        }

        switch (operationChoice)
        {
        case 1:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->insert(value, priority);
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 2:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->extract_max();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 3:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->peek();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 4:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->modify_key(value, priority);
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 5:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->return_size();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        default:
        {
            cout << "There is no such operation\n";
            break;
        }
        }
        break;
    }
    case 2:
    {
        vector<unique_ptr<BinaryHeap>> copies;
        BinaryHeap heap;
        if (dataMethod == 1)
        {
            fill_object(&heap, size);
            copies = prepare_copies(heap, 100);
        }
        else
        {
            fill_object(&heap, filename);
            copies = prepare_copies(heap, 100);
        }

        switch (operationChoice)
        {
        case 1:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->insert(value, priority);
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 2:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->extract_max();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 3:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->peek();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 4:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->modify_key(value, priority);
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        case 5:
        {
            Timer timer;
            for (int i = 0; i < 100; i++)
            {
                timer.start();
                copies[i]->return_size();
                timer.stop();
            }
            cout << "\nThis operation took: " << timer.result() / 100 << " ns\n";
            break;
        }
        default:
        {
            cout << "There is no such operation\n";
            break;
        }
        }
        break;
    }
    default:
    {
        cout << "There is no such data structure\n";
        break;
    }
    }

    return 0;
}
