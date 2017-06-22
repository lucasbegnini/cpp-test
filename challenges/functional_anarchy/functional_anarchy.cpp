#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;
using std::fstream;
using std::string;

class FunctionalAnarchy
{
public:
    int numberOfLines;
    void sort_n_show()
    {
        sort(results.begin(), results.end());

        for(int i=0; i<results.size();i++)
            cout << results[i] << endl;
    }

    void open_file(const char* path)
    {
        string line;
        int aux;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            if(getline(myfile, line))
                numberOfLines = atoi(line.c_str());

            for(int i = 0; i < numberOfLines; i++)
            {
                getline (myfile,line);
                if(line != "\0")
                {
                    aux = atoi(line.c_str());
                    results.push_back(aux);
                }
            }
        }

        myfile.close();
        sort_n_show();
    }

    void insertInResults(int aux)
    {
        results.push_back(aux);
    }

private:
    vector<int> results;
};



int main(int argc, char** argv)
{
    if(argc == 1) {
        FunctionalAnarchy functional;
        cin >> functional.numberOfLines;
        while(functional.numberOfLines--)
        {
            int aux;
            cin >> aux;
            functional.insertInResults(aux);
        }
        functional.sort_n_show();
    }
    if(argc ==2)
    {
        FunctionalAnarchy functional;
        functional.open_file(argv[1]);
        return 0;
    }
}
