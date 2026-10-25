#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student() : name(""), age(0) {}
    Student(string studentName, int studentAge) : name(studentName), age(studentAge) {}

    inline string getName() const { return name; }
    inline int getAge() const { return age; }

    inline void show() const
    {
        cout << name << ", age " << age << '\n';
    }
};

class Group
{
private:
    string name;
    Student* students;
    int size;

public:
    Group(string groupName) : name(groupName), students(0), size(0) {}

    inline string getName() const { return name; }
    inline int getSize() const { return size; }

    void addStudent(string studentName, int age)
    {
        Student* temp = new Student[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = students[i];
        }

        temp[size] = Student(studentName, age);

        delete[] students;
        students = temp;
        size++;
    }

    void deleteStudent(int number)
    {
        if (number < 1 || number > size)
        {
            cout << "not found\n";
            return;
        }

        Student* temp = 0;

        if (size > 1)
        {
            temp = new Student[size - 1];
            int pos = 0;

            for (int i = 0; i < size; i++)
            {
                if (i != number - 1)
                {
                    temp[pos] = students[i];
                    pos++;
                }
            }
        }

        delete[] students;
        students = temp;
        size--;
    }

    void showStudents() const
    {
        cout << "Group: " << name << '\n';

        if (size == 0)
        {
            cout << "no students\n";
        }

        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". ";
            students[i].show();
        }
    }

    ~Group()
    {
        delete[] students;
    }
};

int main()
{
    Group* group = 0;
    int choice;

    do
    {
        cout << "\n1-new group\n";
        cout << "2-add student\n";
        cout << "3-delete student\n";
        cout << "4-show students\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            string groupName;
            cout << "group name: ";
            getline(cin, groupName);

            delete group;
            group = new Group(groupName);
        }
        else if (choice == 2)
        {
            if (group == 0)
            {
                cout << "create a group first\n";
            }
            else
            {
                string studentName;
                int age;

                cout << "student name: ";
                getline(cin, studentName);
                cout << "age: ";
                cin >> age;

                group->addStudent(studentName, age);
            }
        }
        else if (choice == 3)
        {
            if (group == 0)
            {
                cout << "create a group first\n";
            }
            else
            {
                int number;
                cout << "student number: ";
                cin >> number;
                group->deleteStudent(number);
            }
        }
        else if (choice == 4)
        {
            if (group == 0)
            {
                cout << "create a group first\n";
            }
            else
            {
                group->showStudents();
            }
        }
    } while (choice != 0);

    delete group;
}
