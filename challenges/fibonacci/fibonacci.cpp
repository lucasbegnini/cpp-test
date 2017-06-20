#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>

using namespace std;
using std::ifstream;
using std::string;
using std::ofstream;


int fibonacciNumberId;

uint64_t Fibonacci(int n)
{
    int a = 1,b = 1;
    uint64_t x = 0;
    
    if(n == 1)
    { 
       x=a;
    }

    if(n == 2)
    {
       x=b;
    }
    
    for(int i = 3; i<=n; i++)
     {
        x=a+b;
        a=b;
        b=x;
     }
    
    return x;
}

void open_file(char* path)
{
    ifstream is;
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        if(getline(myfile, line))
            fibonacciNumberId = atoi(line.c_str());

        myfile.close();
    }
   cout << fibonacciNumberId << endl; 
    cout << Fibonacci(fibonacciNumberId) << endl;
}

int main(int argc, char** argv)
{
    if(argc == 1)
     { 
        cout << "Paramters missing\n";
        return 0;
     }

    open_file(argv[1]);
	return 0;
}
