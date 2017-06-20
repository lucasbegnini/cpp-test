#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;

int numberOfLines;

void check_anagram(string _word1, string _word2)
{
    string word1 = _word1;
    string word2 = _word2;
    if(word1.size() == word2.size())
    {
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1 == word2 )
            cout << _word1 << " is an anagram of " << _word2  << endl;
        else
            cout << _word1 << " is not an anagram of " << _word2  << endl;
    }else{
        cout << _word1 << " is not an anagram of " << _word2  << endl;
    }
}

void split_variable(const char* line)
{
    //Split line
    std::vector<std::string> result;
    std::istringstream iss(line);    
    for(std::string s; iss >> s;)
    {
        result.push_back(s);
    }
    check_anagram(result[0],result[1]);
}

void open_file(char* path)
{
    ifstream is;
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
    if(argc == 1) { // Sem parametros
        cout << "Parametros faltando\n";
        return 0;
    }

    open_file(argv[1]);
    return 0;
}
