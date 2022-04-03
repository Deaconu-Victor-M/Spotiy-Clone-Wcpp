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
    static void playMusic(char file[101], float sleepTime);
    static float forSleeping(float &sleepTime);
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
    ofstream addPlaylist("data/playlists.txt", std::ios::app);
    ofstream mke(buffer, ofstream::out);
    addPlaylist << name << endl;
    mke.close();
    addPlaylist.close();
}

void SERVICES ::removeFile(char file[101])
{
    char line[101];
    ifstream del("data/playlists.txt");
    ofstream mke("data/hold.txt");
    cout << "Write file name to remove file:\n> ";
    cin >> file;
    char buffer[101];
    sprintf(buffer, "data/playlists/%s.txt", file);
    remove(buffer);

    while (del.getline(line, 101))
    {
        if (strstr(line, file) == NULL)
        {
            mke << line << "\n";
        }
    }
    // {
    //     line.replace(line.find(deleteline), deleteline.length(), "");
    //     temp << line << endl;
    // }
    del.close();
    mke.close();
    remove("data/playlists.txt");
    rename("data/hold.txt", "data/playlists.txt");
    ofstream cre("data/hold.txt", ofstream::out);
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

float SERVICES ::forSleeping(float &sleepTime)
{
    int minsToSec = ((sleepTime * 100) / 100) * 60;
    int seconds = sleepTime * 100;
    return (float)((minsToSec + seconds % 100) / 100.0);
}

// crate a function that plays music from a file
void SERVICES ::playMusic(char file[101], float sleepTime)
{
    int playpause;
    char a = '-';
    char b = '=';
    int barWidth = 50;
    float sleepFor = forSleeping(sleepTime);
    LPCWSTR cmdPlay = L"play mp3";
    LPCWSTR cmdClose = L"close mp3";
    LPCWSTR cmdPause = L"pause mp3";
    time_t t1, t2, previous_pause_time = 0;
    char buffer[101];
    sprintf(buffer, "data/music/%s.mp3", file);

    char file_name[101];
    sprintf(file_name, "open \"%s\" type mpegvideo alias mp3", buffer);

    mciSendString(convertCharArrayToLPCWSTR(file_name), NULL, 0, NULL);
    while (true)
    {

        cin >> playpause;
        system("cls");
        if (playpause == 1)
        {
            // play the audio file
            t1 = time(0);
            mciSendString(cmdPlay, NULL, 0, NULL);
            cout << "\u001b[32mAudio file playing...\u001b[m\n\n";
        }
        else if (playpause == 0)
        {
            // close the file and get out of the loop
            mciSendString(cmdClose, NULL, 0, NULL);
            break;
        }
        int i = 0;

        cout
            << "Press \u001b[31m2\u001b[m to pause the file and press \u001b[31m0\u001b[m to exit the file.\n\u001b[31m>\u001b[m ";
        cin >> playpause;
        // Print initial loading bar
        // cout << "\n[";
        // for (int i = 0; i < barWidth; i++)
        //     cout << a;
        // cout << "]";
        // cout << " \r";

        // cout << "[";
        // while (i < barWidth)
        // {
        //     cout << b;
        //     Sleep(sleepFor*2000);
        //     ++i;
        // }
        // cout << "]\n";

        if (playpause == 2)
        {
            // pause the file
            t2 = time(0);
            mciSendString(cmdPause, NULL, 0, NULL);
            cout << "\u001b[31mAudio file paused...\u001b[m\nEnter \u001b[31m1\u001b[m to play or \u001b[31m0\u001b[m to escape\n\u001b[31m>\u001b[m ";
            previous_pause_time = t2 - t1;
        }
        else if (playpause == 0)
        {
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