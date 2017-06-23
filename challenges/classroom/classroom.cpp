#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>

using namespace std;
using std::string;
class Classroom
{
public:
    int numberOfQueries;

    void getQueries()
    {
        cin.ignore();
        getline(cin, query, '\n');
    }
    void splitQueries()
    {
        std::vector<std::string> result;
        std::istringstream iss(query);
        for(std::string s; iss >> s;)
        {
            result.push_back(s);
        }
    }
private:
    string query;
    vector<int> result;
};
int main(int argc, char** argv)
{
    if(argc == 1)
    {
        Classroom classroom;
        cin >> classroom.numberOfQueries;
        while(classroom.numberOfQueries--)
        {
            classroom.getQueries();
            classroom.splitQueries();

        }

        return 0;
    }
}
