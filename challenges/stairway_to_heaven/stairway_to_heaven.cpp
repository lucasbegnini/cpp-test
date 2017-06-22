#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>


using namespace std;
using std::ifstream;
using std::string;

class StairwayToHeaven
{
public:
    void setHeavenDegress(int in)
    {
        heavenDegrees = in;
    }

    void draw_heaven_degress(int numberOfDegress)
    {
        if(numberOfDegress <= 0)
        {
            cout << "Heaven dont belong to you" << endl;
        }else{
            for(int i=numberOfDegress+1; i>0 ;i--)
            {
                for(int j=0; j < numberOfDegress+1; j++)
                {
                    if(j < i)
                        cout << " ";
                    else
                        cout << "#";
                }
                cout << endl;
            }
        }
    }

    void read_file(char* path)
    {
        string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            if(getline(myfile, line))
                heavenDegrees = atoi(line.c_str());

            myfile.close();
        }
        draw_heaven_degress(heavenDegrees);
    }

private:
    int heavenDegrees;
};




int main(int argc, char** argv)
{
    if(argc == 1) {
        StairwayToHeaven stair;
        int in;
        cin >> in;
        stair.draw_heaven_degress(in);
    }

    if(argc == 2)
    {
        StairwayToHeaven stair;
        stair.read_file(argv[1]);
        return 0;
    }
}
