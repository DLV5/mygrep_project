#include <iostream>
#include <string>

using namespace std;

//0 - no string appearence
//1 or above - string index
int searchAString(string searchFrom, string whatToSearch)
{
    int position = 0;

    size_t result = searchFrom.find(whatToSearch, position);

    return result == string::npos ? 0 : result;
}

int main()
{
    size_t result;
    string searchFrom;
    string whatToSearch;

    cout << "Give a string from which to search for: \n";
    getline(cin, searchFrom);

    cout << "Give search string: \n";
    getline(cin, whatToSearch);

    result = searchAString(searchFrom, whatToSearch);
    if (result > 0)
    {
        cout << "\""
            << whatToSearch
            << "\" found in \""
            << searchFrom
            << "\" in posiion "
            << result;
    }
    else
    {
        cout << "\""
            << whatToSearch
            << "\" NOT found in \""
            << searchFrom;
    }
}

