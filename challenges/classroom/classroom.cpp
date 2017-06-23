#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;
using std::string;
using std::ifstream;
class Classroom
{
public:
    int numberOfQueries;
    bool fileMode;
    ifstream myfile;

    void getQueries()
    {
        if(fileMode)
            getline(myfile,query, '\n');
        else
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
            if(fileMode)
                getline(myfile,auxStudent, '\n');
            else
                getline(cin, auxStudent, '\n');

            students.push_back(auxStudent);
        }
        sort(students.begin(),students.end());
    }

    void findStudent(int numberOfConsults)
    {
        int id;
        for(int i=0;i<numberOfConsults;i++)
        {
            if(fileMode)
            {
                string line;
                getline(myfile,line);
                id = atoi(line.c_str());
            }
            else{
                cin >> id;
            }
         cout << students[id-1] << endl;
        }
    }

    int openFile(char* path)
    {
        string line;
        myfile.open(path);

        if (myfile.is_open())
        {
            if(getline(myfile, line))
                numberOfQueries = atoi(line.c_str());

            while(numberOfQueries--)
            {
                getQueries();
                splitQueries();
                executeQueries();
            }
            myfile.close();
            return 1;
        }else{
            return 0;
        }
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
        classroom.fileMode = false;
        cin >> classroom.numberOfQueries;
        while(classroom.numberOfQueries--)
        {
            classroom.getQueries();
            classroom.splitQueries();
            classroom.executeQueries();

        }

        return 0;
    }

    if(argc == 2)
    {
        Classroom classroom;
        classroom.fileMode = true;
        if(classroom.openFile(argv[1]))
            return 0;
        else
            return -1;

    }
}
