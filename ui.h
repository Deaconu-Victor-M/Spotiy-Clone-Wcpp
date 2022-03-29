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
    static void start();
    static void end();
    static void error();
    static void clear();
    static void progressBar();
    static void musicTable(INPUT_DATA &data);
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
    cout << "+";
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    cout << "+\n";
    cout << "| " << header;
    for (int j = 0; j < maxim + 7 - strlen(header); ++j)
        cout << " ";
    cout << "|\n";

    // data
    //------------------------------------------------------
    // Prints Exit button
    cout << "+";
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    cout << "+\n";
    cout << "| " << 0 << " |  " << arr[n + 1];
    // outputs the remaining space
    for (int j = 0; j < maxim + 2 - strlen(arr[n + 1]); ++j)
        cout << " ";
    cout << "|\n+";
    // outputs divider
    for (int j = 0; j < maxim + 8; ++j)
        cout << "-";
    //------------------------------------------------------

    cout << "+\n";
    for (int i = 0; i < n; ++i)
    {
        // outpus options
        cout << "| " << i + 1 << " |  " << arr[i];
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
    nameLength += maxWordLength(data.musicName, data.musicCount, "Name");
    totalLength += nameLength;
    int artistLength = 0;
    artistLength += maxWordLength(data.artistName, data.musicCount, "Artist");
    totalLength += artistLength;
    cout << "+";
    for (int j = 0; j < totalLength; ++j)
        cout << "-";
    cout << "+\n";
    cout << "|"
         << "No."
         << "|";
    cout << "  Name";
    for (int i = 0; i < (nameLength) + 4 - 6; ++i)
        cout << " ";
    cout << "|";
    cout << "  Artist";
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
    cout << "+\n";
    for (int i = 0; i < data.musicCount; ++i)
    {
        cout << "| " << i + 1 << " |";
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
         << "> ";

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

void UI ::end() {}

// Function to creating loading bar
void UI ::progressBar()
{
    // 0 - black background,
    // F - Green Foreground
    system("color 0F");

    // Initialize char for printing
    // loading bar
    char a = '-';
    char b = '=';

    cout << "[";
    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        cout << a;

    cout << "]";
    printf("\r");

    // Print loading bar progress
    // Print "[" again after line reset
    cout << "[";
    for (int i = 0; i < 26; i++)
    {
        cout << b;

        Sleep(100);
    }
}

void UI ::clear() { system("cls"); }

void UI ::error()
{
    char input;
    cout << divider_end;
    cout << "An error has occured. Invalid input!\n";
    cout << "Press b button to go back:\n";
    cout << "> ";
    cin >> input;
}

#endif