#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

int numberOfLines;
using namespace std;
using std::ifstream;
void show_text(vector<string> result)
{
    cout << result [0] << " is " << result[4] << " years old and lives in " << result[2] <<", " << result[1] << endl;
}

void split_variable(const char* line)
{
    std::vector<std::string> result;
    string out;
    std::istringstream iss(line);
    for(int i=0; i<5; i++)
    {
        getline(iss,out,',');
        result.push_back(out);
    }
    show_text(result);
}

void open_file(char* path)
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
