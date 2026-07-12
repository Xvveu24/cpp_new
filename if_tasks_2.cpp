#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Користувач вводить із клавіатури 7 цілих чисел. Напишіть програму, яка визначає максимальне з цих 7 чисел.
    /*int number;
    int maxNumber;

    cout << "enter number 1: ";
    cin >> maxNumber;

    for (int i = 2; i <= 7; i++)
    {
        cout << "enter number " << i << ": ";
        cin >> number;

        if (number > maxNumber)
        {
            maxNumber = number;
        }
    }

    cout << "max number: " << maxNumber;*/

    //task2 //Завдання 2 Вантажний літак летить з пункту А в пункт С через пункт В. Розрахувати мінімальну кількість палива для дозаправки.
    /*double ab, bc, weight;
    double fuelPerKm;
    double tank = 300;

    cout << "enter distance from A to B: ";
    cin >> ab;
    cout << "enter distance from B to C: ";
    cin >> bc;
    cout << "enter cargo weight: ";
    cin >> weight;

    if (weight <= 500)
    {
        fuelPerKm = 1;
    }
    else if (weight <= 1000)
    {
        fuelPerKm = 4;
    }
    else if (weight <= 1500)
    {
        fuelPerKm = 7;
    }
    else if (weight <= 2000)
    {
        fuelPerKm = 9;
    }
    else
    {
        cout << "plane can not lift this cargo";
        return 0;
    }

    double fuelAB = ab * fuelPerKm;
    double fuelBC = bc * fuelPerKm;

    if (fuelAB > tank || fuelBC > tank)
    {
        cout << "flight is impossible";
    }
    else
    {
        double fuelLeft = tank - fuelAB;
        double needToRefuel = fuelBC - fuelLeft;

        if (needToRefuel < 0)
        {
            needToRefuel = 0;
        }

        cout << "need to refuel in B: " << needToRefuel << " liters";
    }*/

    //task3 //Завдання 3 Зарплата менеджера 200$ + відсоток від продажів. Визначити зарплату 3 менеджерів, кращому дати премію 200$.
    /*double sales1, sales2, sales3;
    double salary1, salary2, salary3;

    cout << "enter sales for manager 1: ";
    cin >> sales1;
    cout << "enter sales for manager 2: ";
    cin >> sales2;
    cout << "enter sales for manager 3: ";
    cin >> sales3;

    if (sales1 < 500)
    {
        salary1 = 200 + sales1 * 0.03;
    }
    else if (sales1 <= 1000)
    {
        salary1 = 200 + sales1 * 0.05;
    }
    else
    {
        salary1 = 200 + sales1 * 0.08;
    }

    if (sales2 < 500)
    {
        salary2 = 200 + sales2 * 0.03;
    }
    else if (sales2 <= 1000)
    {
        salary2 = 200 + sales2 * 0.05;
    }
    else
    {
        salary2 = 200 + sales2 * 0.08;
    }

    if (sales3 < 500)
    {
        salary3 = 200 + sales3 * 0.03;
    }
    else if (sales3 <= 1000)
    {
        salary3 = 200 + sales3 * 0.05;
    }
    else
    {
        salary3 = 200 + sales3 * 0.08;
    }

    if (sales1 >= sales2 && sales1 >= sales3)
    {
        salary1 = salary1 + 200;
        cout << "best manager: 1\n";
    }
    else if (sales2 >= sales1 && sales2 >= sales3)
    {
        salary2 = salary2 + 200;
        cout << "best manager: 2\n";
    }
    else
    {
        salary3 = salary3 + 200;
        cout << "best manager: 3\n";
    }

    cout << "salary manager 1: " << salary1 << "$\n";
    cout << "salary manager 2: " << salary2 << "$\n";
    cout << "salary manager 3: " << salary3 << "$\n";*/

    //task4 //Завдання 4 Вася отримує 50$ за кожні 100 рядків коду. За кожне третє запізнення штраф 20$. Реалізувати меню.
    int choice;

    cout << "1 - count lines for wanted money\n";
    cout << "2 - count how many times Vasya can be late\n";
    cout << "3 - count salary\n";
    cout << "enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        double wantedMoney;
        int late;

        cout << "enter wanted money: ";
        cin >> wantedMoney;
        cout << "enter amount of late times: ";
        cin >> late;

        int fines = late / 3;
        double needMoney = wantedMoney + fines * 20;
        int hundreds = needMoney / 50;

        if (hundreds * 50 < needMoney)
        {
            hundreds = hundreds + 1;
        }

        int lines = hundreds * 100;

        cout << "Vasya need to write: " << lines << " lines";
    }
    else if (choice == 2)
    {
        int lines;
        double wantedMoney;

        cout << "enter lines of code: ";
        cin >> lines;
        cout << "enter wanted money: ";
        cin >> wantedMoney;

        double salary = lines / 100 * 50;
        double canLose = salary - wantedMoney;

        if (canLose < 0)
        {
            cout << "Vasya can not get this money";
        }
        else
        {
            int fines = canLose / 20;
            int late = fines * 3 + 2;

            cout << "Vasya can be late: " << late << " times";
        }
    }
    else if (choice == 3)
    {
        int lines, late;

        cout << "enter lines of code: ";
        cin >> lines;
        cout << "enter amount of late times: ";
        cin >> late;

        double salary = lines / 100 * 50;
        int fines = late / 3;
        double result = salary - fines * 20;

        if (result <= 0)
        {
            cout << "Vasya will get no money";
        }
        else
        {
            cout << "Vasya will get: " << result << "$";
        }
    }
    else
    {
        cout << "wrong choice";
    }

}
