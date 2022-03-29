#ifndef SERVICE_FOLD
#define SERVICE_FOLD

#include <iostream>
#include <string.h>

using namespace std;

class SERVICES
{
public:
    static void optionInput(int &input);
    static void isExit(int &input, bool &doThis);
};

void SERVICES ::optionInput(int &input)
{
    cin >> input;
}

void isExit(int &input, bool &doThis)
{
    if (input == 0)
    {
        doThis = false;
    }
}

//! return to this function
// char* maxWordLength(char input[101][101], int wordsCount)
// {
//     char maxWord[101] = "";
//     for(int i = 0; i < wordsCount; ++i){
//         if(strlen(maxWord) < strlen(input[i]))
//             strcpy(maxWord, input[i]);
//     }
//     return maxWord;
// }

string maxWordLength(string input[101], int wordsCount)
{
    string maxWord = "";
    for (int i = 0; i < wordsCount; ++i)
    {
        if (strlen(maxWord.c_str()) < strlen(input[i].c_str()))
            maxWord = input[i];
    }
    return maxWord;
}



int maxWordLength(char arr[101][101], int wordsCount, char header[101])
{
    char maxWord[101] = "";
    for (int i = 0; i < wordsCount; ++i)
    {
        if (strlen(maxWord) < strlen(arr[i]))
            strcpy(maxWord, arr[i]);
    }
    int maxim = strlen(maxWord);
    if (strlen(header) > maxim)
        maxim = strlen(header);
    return maxim;
}

#endif