#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;

int numberOfLines;

void open_file(char* path)
{
    ifstream is;
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        if(getline(myfile, line))
            numberOfLines = atoi(line.c_str());

        myfile.close();
    }
}

int main(int argc, char** argv)
{
    if(argc == 1) { // Sem parametros
        cout << "Parametros faltando\n";
        return 0;
    }

    open_file(argv[1]);
    return 0;
}
