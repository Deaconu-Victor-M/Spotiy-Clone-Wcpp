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

#endif