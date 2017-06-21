#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

int numberOfLines;
using namespace std;
using std::ifstream;

void open_file(char* path)
{
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
    if(argc == 1) {
        cout << "Parameters missing\n";
        return 0;
    }

    open_file(argv[1]);
    return 0;

	return 0;
}
