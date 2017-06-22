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

    int sum(listOfDirty)
    {
        numberOfDirty = 0;
        for(int i=0; i<listOfDirty;i++)
            numberOfDirty =+ listOfDirty[i];
        return numberOfDirty;
    }

    int split_variable(const char* line)
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
        }else{
            return -1;
        }
    }

private:
    int numberOfLines;
    int numberOfDirty;
    vector<int> listOfDirty;
};
int main(int argc, char** argv)
{
	return 0;
}
