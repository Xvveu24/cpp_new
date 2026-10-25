#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Subscriber
{
private:
    char* fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string info;

public:
    Subscriber(const char* name, string home, string work, string mobile, string extra)
        : fullName(new char[strlen(name) + 1]), homePhone(home), workPhone(work),
          mobilePhone(mobile), info(extra)
    {
        strcpy(fullName, name);
    }

    inline const char* getName() const { return fullName; }
    inline string getHome() const { return homePhone; }
    inline string getWork() const { return workPhone; }
    inline string getMobile() const { return mobilePhone; }
    inline string getInfo() const { return info; }

    inline void show() const
    {
        cout << "Name: " << fullName << '\n';
        cout << "Home: " << homePhone << '\n';
        cout << "Work: " << workPhone << '\n';
        cout << "Mobile: " << mobilePhone << '\n';
        cout << "Info: " << info << '\n';
    }

    ~Subscriber()
    {
        delete[] fullName;
    }
};

class PhoneBook
{
private:
    Subscriber** contacts;
    int size;

public:
    PhoneBook() : contacts(0), size(0) {}

    void add(Subscriber* contact)
    {
        Subscriber** temp = new Subscriber*[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = contacts[i];
        }

        temp[size] = contact;
        delete[] contacts;
        contacts = temp;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "not found\n";
            return;
        }

        delete contacts[index];

        Subscriber** temp = 0;
        if (size > 1)
        {
            temp = new Subscriber*[size - 1];
            int pos = 0;

            for (int i = 0; i < size; i++)
            {
                if (i != index)
                {
                    temp[pos] = contacts[i];
                    pos++;
                }
            }
        }

        delete[] contacts;
        contacts = temp;
        size--;
    }

    void showAll() const
    {
        if (size == 0)
        {
            cout << "phone book is empty\n";
        }

        for (int i = 0; i < size; i++)
        {
            cout << "\n" << i + 1 << ".\n";
            contacts[i]->show();
        }
    }

    void search(const char* name) const
    {
        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (strcmp(contacts[i]->getName(), name) == 0)
            {
                contacts[i]->show();
                found = true;
            }
        }

        if (found == false)
        {
            cout << "not found\n";
        }
    }

    bool save(const char* fileName) const
    {
        ofstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            file << contacts[i]->getName() << '\n';
            file << contacts[i]->getHome() << '\n';
            file << contacts[i]->getWork() << '\n';
            file << contacts[i]->getMobile() << '\n';
            file << contacts[i]->getInfo() << '\n';
        }

        file.close();
        return true;
    }

    bool load(const char* fileName)
    {
        ifstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        clear();

        string name, home, work, mobile, extra;

        while (getline(file, name))
        {
            if (!getline(file, home) || !getline(file, work) ||
                !getline(file, mobile) || !getline(file, extra))
            {
                break;
            }

            add(new Subscriber(name.c_str(), home, work, mobile, extra));
        }

        file.close();
        return true;
    }

    void clear()
    {
        for (int i = 0; i < size; i++)
        {
            delete contacts[i];
        }

        delete[] contacts;
        contacts = 0;
        size = 0;
    }

    ~PhoneBook()
    {
        clear();
    }
};

int main()
{
    PhoneBook book;
    int choice;

    do
    {
        cout << "\n1-add\n";
        cout << "2-delete\n";
        cout << "3-search\n";
        cout << "4-show all\n";
        cout << "5-save\n";
        cout << "6-load\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            string name, home, work, mobile, extra;

            cout << "full name: ";
            getline(cin, name);
            cout << "home phone: ";
            getline(cin, home);
            cout << "work phone: ";
            getline(cin, work);
            cout << "mobile phone: ";
            getline(cin, mobile);
            cout << "info: ";
            getline(cin, extra);

            book.add(new Subscriber(name.c_str(), home, work, mobile, extra));
        }
        else if (choice == 2)
        {
            int number;
            cout << "contact number: ";
            cin >> number;
            book.remove(number - 1);
        }
        else if (choice == 3)
        {
            string name;
            cout << "full name: ";
            getline(cin, name);
            book.search(name.c_str());
        }
        else if (choice == 4)
        {
            book.showAll();
        }
        else if (choice == 5)
        {
            if (book.save("phonebook.txt"))
            {
                cout << "saved\n";
            }
            else
            {
                cout << "file error\n";
            }
        }
        else if (choice == 6)
        {
            if (book.load("phonebook.txt"))
            {
                cout << "loaded\n";
            }
            else
            {
                cout << "file error\n";
            }
        }
    } while (choice != 0);
}
