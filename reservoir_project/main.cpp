#include <iostream>
#include <limits>
#include "Reservoir.h"
using namespace std;

ReservoirType inputType()
{
    int type;

    cout << "0-sea 1-lake 2-pool 3-pond 4-other: ";
    cin >> type;

    if (type < 0 || type > 4)
    {
        return Other;
    }

    return (ReservoirType)type;
}

int main()
{
    ReservoirList list;
    int choice;

    do
    {
        cout << "\n1-add\n";
        cout << "2-delete\n";
        cout << "3-show\n";
        cout << "4-compare\n";
        cout << "5-save text\n";
        cout << "6-save binary\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            char name[100];
            double width, length, depth;

            cout << "name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(name, 100);
            ReservoirType type = inputType();
            cout << "width length max depth: ";
            cin >> width >> length >> depth;

            Reservoir reservoir(name, width, length, depth, type);
            list.add(reservoir);
        }
        else if (choice == 2)
        {
            int number;
            cout << "number: ";
            cin >> number;

            if (!list.remove(number - 1))
            {
                cout << "not found\n";
            }
        }
        else if (choice == 3)
        {
            list.show();
        }
        else if (choice == 4)
        {
            int first, second;
            cout << "two numbers: ";
            cin >> first >> second;

            const Reservoir* a = list.get(first - 1);
            const Reservoir* b = list.get(second - 1);

            if (a == 0 || b == 0)
            {
                cout << "not found\n";
            }
            else
            {
                int result = a->compareSurface(*b);

                if (result == 2)
                {
                    cout << "different types\n";
                }
                else if (result == 1)
                {
                    cout << a->getName() << " has larger surface\n";
                }
                else if (result == -1)
                {
                    cout << b->getName() << " has larger surface\n";
                }
                else
                {
                    cout << "surfaces are equal\n";
                }
            }
        }
        else if (choice == 5)
        {
            cout << (list.saveText("reservoirs.txt") ? "saved\n" : "file error\n");
        }
        else if (choice == 6)
        {
            cout << (list.saveBinary("reservoirs.bin") ? "saved\n" : "file error\n");
        }
    } while (choice != 0);
}
