#ifndef SERVICE_FOLD
#define SERVICE_FOLD

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class SERVICES
{
public:
    static void optionInput(int &input);
    static void isExit(int &input, bool &doThis);
    static void cretePlaylistFile(char name[101]);
    static void removeFile(char file[101]);
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

void SERVICES ::cretePlaylistFile(char name[101])
{

    cin >> name;
    char buffer[101];
    sprintf(buffer, "data/playlists/%s.txt", name);
    ofstream mke(buffer, ofstream::out);
}

void SERVICES ::removeFile(char file[101])
{
    cout << "Write file name to remove file:\n> ";
    cin >> file;
    char buffer[101];
    sprintf(buffer, "data/playlists/%s.txt", file);
    remove(buffer);
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