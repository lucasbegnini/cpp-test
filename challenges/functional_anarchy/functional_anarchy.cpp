#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;
using std::fstream;
using std::string;

void open_file(char* path)
{
    vector<int> results;
    string line;
    int aux;
    ifstream myfile (path);
    if (myfile.is_open())
    {

        while(!myfile.eof())
        {
            getline (myfile,line);
            aux = atoi(line.c_str());
            results.push_back(aux);
        }
    }
    myfile.close();
}


int main(int argc, char** argv)
{
    if(argc == 1) {
        cout << "Parameters missing\n";
        return 0;
    }

    open_file(argv[1]);
    return 0;
}
