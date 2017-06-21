#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>


using namespace std;
using std::ifstream;
using std::string;

int heavenDegrees;

void read_file(char* path)
{
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        if(getline(myfile, line))
            heavenDegrees = atoi(line.c_str());

        myfile.close();
    }
}

int main(int argc, char** argv)
{
    if(argc == 1) {
        cout << "Parameters missing\n";
        return 0;
    }

    read_file(argv[1]);
	return 0;
}
