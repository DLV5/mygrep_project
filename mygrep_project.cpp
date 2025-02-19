#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;

//0 - no string appearence
//1 or above - string index
int searchAString(string searchFrom, string whatToSearch)
{
    int position = 0;

    size_t result = searchFrom.find(whatToSearch, position);

    return result == string::npos ? 0 : result;
}

vector<string> searchAFile(ifstream& file, string whatToSearch)
{
    vector<string> result;
    string lineToSearch;

    while (!file.eof())
    {
        getline(file, lineToSearch);
        int lineSearchResult = searchAString(lineToSearch, whatToSearch);

        if (lineSearchResult > 0)
        {
            result.push_back(lineToSearch);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    vector<string> result;
    string whatToSearch;

    try
    {
        //We want to use this input method only 
        // when program started witout arguments
        if (argc == 1)
        {
            size_t result;
            string searchFrom;

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

            return 0;
        }

        ifstream textFileToSearch(argv[2], std::ifstream::in);

        result = searchAFile(textFileToSearch, argv[1]);

        for (uint_fast8_t i = 0; i < result.size(); i++)
        {
            cout << result[i] << " \n";
        }
    } 	catch (exception e)
	{
		cout << "Error: " << e.what();
	}
}

