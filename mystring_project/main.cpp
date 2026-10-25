#include <iostream>
#include <utility>
#include "MyString.h"
using namespace std;

int main()
{
    MyString empty;
    MyString first("Hello C++");
    MyString copy(first);

    first[0] = 'h';
    cout << "empty: '" << empty << "', length: " << empty.getLength() << '\n';
    cout << "first: " << first << '\n';
    cout << "copy: " << copy << '\n';

    copy = first;
    MyString joined = first + MyString("!!!");
    cout << "joined: " << joined << '\n';

    MyString moved(std::move(joined));
    cout << "moved: " << moved << '\n';
    cout << "source after move: '" << joined << "'\n";

    empty = std::move(moved);
    cout << "empty after move assignment: " << empty << '\n';

    const MyString& readOnly = first;
    cout << "first character: " << readOnly[0] << '\n';
}
