#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
using std::ifstream;
using std::string;
using std::ofstream;


int fibonacciNumberId;

void open_file(char* path)
{
    ifstream is;
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        if(getline(myfile, line))
            fibonacciNumberId = atoi(line.c_str());

        myfile.close();
    }
}

int main(int argc, char** argv)
{
    if(argc == 1)
     { 
        cout << "Paramters missing\n";
        return 0;
     }

    open_file(argv[1]);
	return 0;
}
