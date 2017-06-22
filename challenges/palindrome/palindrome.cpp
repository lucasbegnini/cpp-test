#include <iostream>
#include <string>

using namespace std;
class Palindrome
{
public:
    int check_palindrome(string in)
    {
        int reverse = 0;
        for(int i =0; i < in.size()/2; i++)
        {
            reverse = in.length() - i -1;
            if(in[i] != in[reverse])
                return 0;
        }
        return 1;
    }

private:

};
int main(int argc, char** argv)
{
	return 0;
}
