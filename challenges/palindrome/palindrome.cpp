#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
}
