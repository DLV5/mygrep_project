#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;

enum SettingsOptions
{
    DisplayLineNumbers,
    DisplayOccurenceAmount,
    EnableReverceSearch,
    DisableCaseSensitivity
};

struct mathingString
{
    int index;
    string line;
};

struct settings
{
    private: 
        vector<SettingsOptions> options;
        vector<char> optionsChars;

    public :
        void addOption(char option)
    {
        if(find(optionsChars.begin(), optionsChars.end(), option) != optionsChars.end())
		{
            throw exception("You cannot set the same settings paramether twice!");
        }

        switch (option)
        {
            case 'l':
				options.push_back(DisplayLineNumbers);
				break;
			case 'o':
				options.push_back(DisplayOccurenceAmount);
				break;
			case 'r':
				options.push_back(EnableReverceSearch);
				break;
			case 'i':
				options.push_back(DisableCaseSensitivity);
				break;
			default:
				throw exception("Unknown settings paramether");
        }

        optionsChars.push_back(option);
    }

        bool isDisplayLineNumbersEnabled()
	{
		return find(options.begin(), options.end(), DisplayLineNumbers) != options.end();
	}
    
        bool isDisplayOccurenceAmountEnabled()
	{
		return find(options.begin(), options.end(), DisplayOccurenceAmount) != options.end();
	}
    
        bool isReverceSearchEnabled()
	{
		return find(options.begin(), options.end(), EnableReverceSearch) != options.end();
	}
    
        bool isCaseSensitivityEnabled()
	{
		return find(options.begin(), options.end(), DisableCaseSensitivity) == options.end();
	}
};

void processSettings(string settingsString, settings* programSettings)
{
    if(settingsString.substr(0, 2) == "-o")
	{
		settingsString = settingsString.substr(2);
    }
    else
    {
        throw exception("Settings paramether should start with \"-o\"");
    }

    while (settingsString.length() > 0)
    {
        programSettings->addOption(settingsString[0]);
        settingsString = settingsString.substr(1);
    }
}
//0 - no string appearence
//1 or above - string index
int searchAString(string searchFrom, string whatToSearch)
{
    int position = 0;

    size_t result = searchFrom.find(whatToSearch, position);

    return result == string::npos ? 0 : result;
}

vector<mathingString> searchAFile(ifstream& file, string whatToSearch)
{
    vector<mathingString> result;
    string lineToSearch;

    while (!file.eof())
    {
        getline(file, lineToSearch);
        int lineSearchResult = searchAString(lineToSearch, whatToSearch);

        if (lineSearchResult > 0)
        {
            mathingString res = {lineSearchResult, lineToSearch};
            result.push_back(res);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    vector<mathingString> result;
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

        //We always want to use last arguments as file name
        ifstream textFileToSearch(argv[argc - 1], std::ifstream::in);
        settings programSettings = {};

        if (!textFileToSearch.is_open())
            throw exception("File not found");

        if(argc > 3)
            processSettings(argv[argc - 3], &programSettings);

        //We always want to use last but one argument as string to search
        result = searchAFile(textFileToSearch, argv[argc - 2]);
        textFileToSearch.close();

        for (uint_fast8_t i = 0; i < result.size(); i++)
        {
            if(programSettings.isDisplayLineNumbersEnabled())
				cout << result[i].index << ":     ";
            cout << result[i].line << " \n";

        }
        
        if(programSettings.isDisplayOccurenceAmountEnabled())
            cout << "Occurrences of lines containing "<< whatToSearch << ": " << result.size() << "\n";

        if(result.size() == 0)
		{
			cout << "No mathing strings were found in the file";
		}

        return 0;
    } 	catch (exception e)
	{
		cout << "Error: " << e.what();
	}
}

