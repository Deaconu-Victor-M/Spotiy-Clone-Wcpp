#include <iostream>

#include "service.hpp"
#include "ui.h"

int main()
{
    bool isRunning = true;
    INPUT_DATA data;
    int choice;
    int _case = -1;

    while (isRunning)
    {
        bool goBack = true;
        UI ::clear();
        UI ::start();
        SERVICES ::optionInput(choice);
        switch (choice)
        {
        case 0:
            isRunning = false;

            break;
        case 1:
        {
            while (true)
            {
                UI ::clear();
                MUSIC ::readGenre(data);
                UI ::showGenres(data);
                SERVICES ::optionInput(_case);
                if (_case > data.numberOfGenres)
                {
                    UI ::clear();
                    UI ::error();
                }
                if (_case == 0)
                    break;
                else
                {
                    while (true)
                    {
                        UI ::clear();
                        MUSIC ::readMusic(data, _case);
                        UI ::showMusic(data);
                        int n;
                        cin >> n;
                        if (n == 0)
                            break;
                    }
                }
            }
        }

        break;
        case 2:
        {
            int ok = 1;
            while (ok == 1)
            {
                char name[101];
                UI ::clear();
                UI ::inputPlaylistName();
                SERVICES ::cretePlaylistFile(name);
                UI ::succesfullyCreatedName(name, ok);
            }
        }

        break;
        case 3:
        {
            int ok = 1;
            while (ok == 1)
            {
                UI ::clear();
                MUSIC ::readGenre(data);
                UI ::showGenres(data);
                SERVICES ::optionInput(_case);
                if (_case > data.numberOfGenres)
                {
                    UI ::clear();
                    UI ::error();
                }
                if (_case == 0)
                    ok = 0;
                else if (_case < data.numberOfGenres)
                {
                    bool show = true;
                    char name[101];
                    while (show)
                    {
                        UI ::clear();
                        MUSIC ::readMusic(data, _case);
                        UI ::showMusic(data);
                        int n;
                        cout << "Select the song to add to a playlist:\n> ";
                        cin >> n;
                        if (n == 0)
                            show = false;
                        else
                            MUSIC ::addSongToPlylist(data, name, n);
                    }
                }
            }
        }
        break;
        case 4:
        {
            char file[101];
            SERVICES ::removeFile(file);
        }
        break;
        case 5:
        {
            UI ::clear();
            MUSIC ::readPlaylists(data);
            UI ::showPlaylists(data);
            SERVICES ::optionInput(_case);
            if (_case > data.numberOfPlaylists)
            {
                UI ::clear();
                UI ::error();
            }
            if (_case == 0)
                break;
            else
            {
                while (true)
                {
                    UI ::clear();
                    MUSIC ::readMusicFromPlaylist(data, _case);
                    UI ::showMusic(data);
                    int n;
                    cin >> n;
                    if (n == 0)
                        break;
                }
            }
        }
        break;
        default:
            UI ::clear();
            UI ::error();
            break;
        }
    }

    return 0;
}