#ifndef UI_FOLD
#define UI_FOLD

#include <string.h>
#include <windows.h>

#include <iostream>

#include "models/genres.hpp"
#include "service.hpp"

using namespace std;

const char *divider_welcome =
    " ===================[ Welcome to Spoty ]===================\n\n";
const char *divider_start =
    " ===================[ Spotify Clone ]===================\n\n";
const char *divider_end =
    "========================================================\n";

class UI
{
public:
    // static void table();
    static void welcome();
    static void showGenres(INPUT_DATA &data);
    static void showMusic(INPUT_DATA &data);
    static void showPlaylists(INPUT_DATA &data);
    static void start();
    static void end();
    static void error();
    static void clear();
    static void progressBar();
    static void musicTable(INPUT_DATA &data);
    static void inputPlaylistName();
    static void succesfullyCreatedName(char name[101], int &ok);
    static void inputSongToPlay();
};

// Function to create welcome menu
void UI ::welcome()
{
    cout << divider_welcome;
    cout << "Please enter a pasword:\n";
    cout << "> ";
}

void optionsTable(char arr[101][101], int n, int max, char header[101])
{
    // gets the max length of words and then compares it to the title
    strcpy(arr[n + 1], "Exit");
    char maxWord[101] = "";
    for (int i = 0; i < n; ++i)
    {
        if (strlen(maxWord) < strlen(arr[i]))
            strcpy(maxWord, arr[i]);
    }
    int maxim = strlen(maxWord);
    if (strlen(header) > maxim)
        maxim = strlen(header);
    // header
    cout << "\u001b[34m+";
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    cout << "+\n";
    cout << "| " << header << "";
    for (int j = 0; j < maxim + 7 - strlen(header); ++j)
        cout << " ";
    cout << "|\n";

    // data
    //------------------------------------------------------
    // Prints Exit button
    cout << "+";
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    cout << "+\u001b[m\n";
    cout << "\u001b[31m| " << 0
         << " |  " << arr[n + 1];
    // outputs the remaining space
    for (int j = 0; j < maxim + 2 - strlen(arr[n + 1]); ++j)
        cout << " ";
    cout << "|\n+";
    // outputs divider
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    //------------------------------------------------------

    cout << "+\u001b[m\n";
    for (int i = 0; i < n; ++i)
    {
        // outpus options
        cout << "| \u001b[32m" << i + 1 << "\u001b[m |  " << arr[i];
        // outputs the remaining space
        for (int j = 0; j < maxim + 2 - strlen(arr[i]); ++j)
            cout << " ";
        cout << "|\n+";
        // outputs divider
        for (int j = 0; j < maxim + 8; ++j)
            cout << "-";
        cout << "+\n";
    }
}

void UI ::musicTable(INPUT_DATA &data)
{
    int totalLength = 51;
    int nameLength = 0;
    nameLength += maxWordLength(data.musicName, data.musicCount, (char *)"Name");
    totalLength += nameLength;
    int artistLength = 0;
    artistLength += maxWordLength(data.artistName, data.musicCount, (char *)"Artist");
    totalLength += artistLength;
    cout << "\u001b[34m+";
    for (int j = 0; j < totalLength; ++j)
        cout << "-";
    cout << "+\n";
    cout << "|"
         << "No."
         << "|  ";
    cout << "Name";
    for (int i = 0; i < (nameLength) + 4 - 6; ++i)
        cout << " ";
    cout << "|  ";
    cout << "Artist";
    for (int i = 0; i < (artistLength) + 4 - 8; ++i)
        cout << " ";
    cout << "|  ";
    cout << "Rating"
         << "  |  "
         << "Length"
         << "  |  "
         << "Publication"
         << "  |\n";
    cout << "+";
    for (int j = 0; j < totalLength; ++j)
        cout << "-";
    cout << "+\u001b[m\n";
    for (int i = 0; i < data.musicCount; ++i)
    {
        cout << "| \u001b[32m" << i + 1 << "\u001b[m |";
        cout << "  " << data.musicName[i];
        for (int j = 0; j < (nameLength + 2 - strlen(data.musicName[i])); ++j)
            cout << " ";
        cout << "|";
        cout << "  " << data.artistName[i];
        for (int j = 0; j < (artistLength + 2 - strlen(data.artistName[i])); ++j)
            cout << " ";
        cout << "|  ";
        cout << data.rating[i] << "    |  " << data.length[i] << "    |  ";
        cout << data.publication[i].day << "." << data.publication[i].month << "." << data.publication[i].year;
        if (data.publication[i].day < 10 && data.publication[i].month < 10)
            cout << "     |\n";
        else if ((data.publication[i].day < 10 && data.publication[i].month >= 10) || (data.publication[i].day >= 10 && data.publication[i].month < 10))
            cout << "    |\n";
        else
            cout << "   |\n";
        cout << "+";
        for (int j = 0; j < totalLength; ++j)
            cout << "-";
        cout << "+\n";
    }
}

void UI ::start()
{
    int n = 5; // the amount of options
    char options[21][101] = {"Explore genres", "Create playlist",
                             "Add melody to playlist", "Delete playlist",
                             "View playlist"}; // all the options
    cout << divider_start;
    optionsTable(options, n, 25, (char *)"Options");
    cout << "\n"
         << divider_end;
    cout << "Select an option:\n"
         << "\u001b[31m> \u001b[m";

    //! user
    // explore genres
    // create playist
    // add music to playlist
    // delete playlist
    // edit playlist

    //! admin
    // add a music
    // create a genre
    // delete music
    // delete genre -- note: with the deletion of a genre you will implicitly
    // delete all the "audio"/music that comes with it
}

void UI ::inputSongToPlay()
{
    cout << "Enter the name of the song you want to play\n\u001b[31m> \u001b[m";
}

void UI ::inputPlaylistName()
{
    cout << "Enter playlist name:\n";
    cout << "\u001b[31m> \u001b[m";
}

void UI ::succesfullyCreatedName(char name[101], int &ok)
{
    cout << "\u001b[32m" << divider_end;
    cout << name << " playlist was created successfully\u001b[m\nPress 0 to go back:\n> ";
    cin >> ok;
}

void UI ::showGenres(INPUT_DATA &data)
{
    cout << divider_end << "\n";
    optionsTable(data.genre, data.numberOfGenres, 25,
                 (char *)"Genres avalible");
    cout << "Select an option to see all music avalible:\n"
         << "> ";
}

void UI ::showMusic(INPUT_DATA &data)
{
    musicTable(data);
    // for (int i = 0; i < data.musicCount; ++i)
    // {
    //     cout << data.musicName[i] << "\n";
    //     cout << data.artistName[i] << "\n";
    //     cout << data.rating[i] << "\n";
    //     cout << data.length[i] << "\n";
    //     cout << data.publication[i].day  << "."<< data.publication[i].month << "." << data.publication[i].year << "\n";
    // }
}

void UI ::showPlaylists(INPUT_DATA &data)
{
    cout << divider_end << "\n";
    optionsTable(data.playlists, data.numberOfPlaylists, 25,
                 (char *)"Your playlists");
    cout << "Select an option to see songs in your playlist:\n"
         << "> ";
}

void UI ::end() {}

// Function to creating loading bar
// void UI ::progressBar(float &progress)
// {
//     int barWidth = 50;

//     cout << "[";
//     for (int i = 0; i < barWidth; i++)
//         cout << "-";
//     cout << "]";
//     cout << " \r";
//     int pos = barWidth * progress;
//     cout << "[";
//     for (int i = 0; i < barWidth; ++i)
//     {
//         if (i < pos)
//             cout << "=";
//         else
//             cout << " ";
//         Sleep(10);
//     }
//     cout << "] " << int(progress) << " %\r";
//     cout.flush();
//     Sleep(100);
// }

void UI ::progressBar()
{

    // float &progress, INPUT_DATA &data
    //  Initialize char for printing
    //  loading bar
    int i = 0;
    char a = '-';
    char b = '=';
    int barWidth = 100;

    // Print initial loading bar
    cout << "[";
    for (int i = 0; i < barWidth; i++)
        cout << a;
    cout << "]";
    cout << " \r";

    cout << "[";
    while (i < barWidth)
    {
        cout << b;
        Sleep(29.5);
        ++i;
    }
    cout << "]\r";

    // << int(progress) << " %\r"
}

void UI ::clear() { system("cls"); }

void UI ::error()
{
    char input;
    cout << divider_end;
    cout << "\n\u001b[31mAn error has occured. Invalid input!\u001b[m\n";
    cout << "Press b button to go back:\n";
    cout << "\u001b[31m> \u001b[m";
    cin >> input;
}

#endif
