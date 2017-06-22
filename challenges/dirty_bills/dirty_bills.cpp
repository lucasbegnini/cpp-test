#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;
using std::ifstream;
using std::string;

class DirtyBills
{
public:
    DirtyBills(){}

    int sum()
    {
        numberOfDirty = 0;
        for(int i=0; i<listOfDirty.size();i++)
            numberOfDirty += listOfDirty[i];
        return numberOfDirty;
    }

    int split_variable(string line)
    {
        //Split line
        std::vector<std::string> result;
        std::istringstream iss(line);
        for(std::string s; iss >> s;)
        {
            result.push_back(s);
        }
        if(result[1] == "dirty")
            listOfDirty.push_back(atoi(result[0].c_str()));
    }

    int open_file(char* path)
    {
        string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            if(getline(myfile, line))
                numberOfLines = atoi(line.c_str());

            for(int i = 0; i < numberOfLines; i++)
            {
                getline (myfile,line);
                split_variable(line.c_str());
            }
            myfile.close();
            return 0;
        }else{
            return -1;
        }
    }

    void setNumberOfLines(int number)
    {
        numberOfLines = number;
    }

    int getNumberOfLines()
    {
        return numberOfLines;
    }

private:
    int numberOfLines;
    int numberOfDirty;
    vector<int> listOfDirty;
};
int main(int argc, char** argv)
{
    if(argc == 1) {
        DirtyBills dirty;
        int numberIn;
        cin >> numberIn;
        dirty.setNumberOfLines(numberIn);

        int numberOfMonkeys = dirty.getNumberOfLines();
        while(numberOfMonkeys--)
        {
            string line;
            cin.ignore();
            getline(cin, line, '\n');
            dirty.split_variable(line);
        }
        if(dirty.sum() > 0)
            cout << "There are " << dirty.sum() << " dirty bills" << endl;
        else
            cout << "There are no dirty bills" << endl;
    }
    if(argc == 2)
    {
        DirtyBills _dirty;
        _dirty.open_file(argv[1]);
        if(_dirty.sum() > 0)
            cout << "There are " << _dirty.sum() << " dirty bills" << endl;
        else
            cout << "There are no dirty bills" << endl;
    }

    return 0;
}
