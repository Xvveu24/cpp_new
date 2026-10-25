#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    // task1
    /*const int rows = 3;
    const int columns = 4;
    int numbers[rows][columns];

    cout << "Enter array elements:\n";
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cin >> numbers[row][column];
        }
    }

    int sum = 0;
    int minimum = numbers[0][0];
    int maximum = numbers[0][0];

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            sum += numbers[row][column];

            if (numbers[row][column] < minimum)
            {
                minimum = numbers[row][column];
            }

            if (numbers[row][column] > maximum)
            {
                maximum = numbers[row][column];
            }
        }
    }

    double average = static_cast<double>(sum) / (rows * columns);

    cout << "Sum: " << sum << '\n';
    cout << "Average: " << average << '\n';
    cout << "Minimum: " << minimum << '\n';
    cout << "Maximum: " << maximum << '\n';*/

    // task2
    /*const int rows = 3;
    const int columns = 4;
    int numbers[rows][columns];

    cout << "Enter array elements:\n";
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cin >> numbers[row][column];
        }
    }

    int totalSum = 0;
    int columnSums[columns] = {};

    cout << "\nMatrix with row sums:\n";
    for (int row = 0; row < rows; row++)
    {
        int rowSum = 0;

        for (int column = 0; column < columns; column++)
        {
            cout << setw(4) << numbers[row][column];
            rowSum += numbers[row][column];
            columnSums[column] += numbers[row][column];
        }

        totalSum += rowSum;
        cout << "  |" << setw(4) << rowSum << '\n';
    }

    cout << "--------------------------\n";
    for (int column = 0; column < columns; column++)
    {
        cout << setw(4) << columnSums[column];
    }
    cout << "  |" << setw(4) << totalSum << '\n';*/

    // task3
    const int rows = 5;
    const int firstColumns = 10;
    const int secondColumns = 5;

    int firstArray[rows][firstColumns];
    int secondArray[rows][secondColumns];

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < firstColumns; column++)
        {
            firstArray[row][column] = rand() % 51;
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < secondColumns; column++)
        {
            secondArray[row][column] = firstArray[row][column * 2]
                + firstArray[row][column * 2 + 1];
        }
    }

    cout << "First array (5x10):\n";
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < firstColumns; column++)
        {
            cout << setw(4) << firstArray[row][column];
        }
        cout << '\n';
    }

    cout << "\nSecond array (5x5):\n";
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < secondColumns; column++)
        {
            cout << setw(4) << secondArray[row][column];
        }
        cout << '\n';
    }
}
