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
        std::istringstream iss(query);
        for(std::string s; iss >> s;)
        {
            result.push_back(atoi(s.c_str()));
        }
    }

    void executeQueries()
    {
        if(result[result.size()-2] == 1)
        {
            addStudents(result[result.size()-1]);

        }

        if(result[result.size()-2] == 2)
        {
            findStudent(result[result.size()-1]);
        }
    }

    void addStudents(int numberOfStudents)
    {
        string auxStudent;
        for(int i = 0; i< numberOfStudents;i++)
        {
            getline(cin, auxStudent, '\n');
            students.push_back(auxStudent);
        }
        sort(students.begin(),students.end());
    }

    void findStudent(int numberOfConsults)
    {
        int id;
        vector<int> ids;
        for(int i=0;i<numberOfConsults;i++)
        {
            cin >> id;
            ids.push_back(id);
        }
        for(int i=0;i<ids.size();i++)
            cout << students[ids[i-1]] << endl;
    }

private:
    string query;
    vector<int> result;
    vector<string> students;
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
            classroom.executeQueries();

        }

        return 0;
    }
}
