#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;
using std::ifstream;
using std::string;

class Palindrome
{
public:
    int numberOfPalindromes;
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

    void insertWords(string word)
    {
        words.push_back(word);
    }

    void verifyWords()
    {
        for(int i = 0; i<words.size();i++)
        {
            if(check_palindrome(words[i]))
                cout << words[i] << " is palindrome" << endl;
            else
                cout << words[i] << " is not a palindrome" << endl;
        }
    }

    int openFile(char* path)
    {
        string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            if(getline(myfile, line))
                numberOfPalindromes = atoi(line.c_str());

            for(int i = 0; i < numberOfPalindromes; i++)
            {
                getline (myfile,line);
                insertWords(line);
            }
            verifyWords();
            myfile.close();
            return 0;
        }else{
            return -1;
        }
    }

private:
    vector<string> words;

};
int main(int argc, char** argv)
{
    if(argc == 1)
    {
        Palindrome pali;
        cin >> pali.numberOfPalindromes;
        while(pali.numberOfPalindromes--)
        {
            string line;
            cin >> line;
            pali.insertWords(line);
        }
        pali.verifyWords();
        return 0;
    }

    if( argc == 2)
    {
        Palindrome pali;
        if(!pali.openFile(argv[1]))
            return 0;
        else
            return -1;
    }
}
