#ifndef SERVICE_FOLD
#define SERVICE_FOLD

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#define UNICODE 1
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>

using namespace std;

class SERVICES
{
public:
    static void optionInput(int &input);
    static void isExit(int &input, bool &doThis);
    static void cretePlaylistFile(char name[101]);
    static void removeFile(char file[101]);
    static void stopMusic();
    static void playMusic(char file[101]);
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

void SERVICES :: removeFile(char file[101])
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

wchar_t *convertCharArrayToLPCWSTR(const char *charArray)
{
    wchar_t *wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

//crate a function that plays music from a file
void SERVICES :: playMusic(char file[101])
{
    int playpause;
    
    LPCWSTR cmdPlay = L"play mp3";
    LPCWSTR cmdClose = L"close mp3";
    LPCWSTR cmdPause = L"pause mp3";
    time_t t1, t2, previous_pause_time = 0;
    char buffer[101];
    sprintf(buffer, "data/music/%s.mp3", file);

    char file_name[101];
    sprintf(file_name, "open \"%s\" type mpegvideo alias mp3", buffer);
    
    mciSendString(convertCharArrayToLPCWSTR(file_name), NULL, 0, NULL);
    while(true){

        cin >> playpause;

        if(playpause == 1){
            // play the audio file
            t1 = time(0);
            mciSendString(cmdPlay, NULL, 0, NULL);
            cout << "Audio file playing...\n\n";
        } else if(playpause == 0){
            // close the file and get out of the loop
            mciSendString(cmdClose, NULL, 0, NULL);
            break;
        }

        cout << "Press 2 to pause the file and press 0 to exit the file." << endl;

        cin >> playpause;

        if(playpause == 2){
            // pause the file
            t2 = time(0);
            mciSendString(cmdPause, NULL, 0, NULL);
            cout << "Audio file paused...\n\n";
            previous_pause_time = t2 - t1;
        } else if(playpause == 0){
            // close the file and get out of the loop
            mciSendString(cmdClose, NULL, 0, NULL);
            break;
        }
    }
}

// int playpause;
// while (true)
// {
//     UI ::clear();
//     SERVICES ::playMusic(data.musicName[song - 1]);
//     SERVICES ::optionInput(playpause);
//     if (playpause == 0)
//         break;
//     else if (playpause == 1)
//         SERVICES ::stopMusic();
// }

#endif