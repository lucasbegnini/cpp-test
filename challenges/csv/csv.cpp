#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using std::ifstream;
class Csv
{
public:
    Csv() {}
    int numberOfLines;
    void show_text(vector<string> result)
    {
        cout << result [0] << " is " << result[4] << " years old and lives in " << result[2] <<", " << result[1] << endl;
    }


    void split_variable(string line)
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
        } else {
            return -1;
        }
    }

private:
};


int main(int argc, char** argv)
{
    if(argc == 1) {
        Csv csv;
        cin >> csv.numberOfLines;
        while(csv.numberOfLines--)
        {
            string line;
            cin.ignore();
            getline(cin, line, '\n');
            csv.split_variable(line);
        }
    }
    Csv csv;
    if(!csv.open_file(argv[1]))
        return 0;
    else
        return -1;
}
