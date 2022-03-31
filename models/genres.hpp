#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdio>

using namespace std;

struct DATA
{
    unsigned int day, month, year;
};

struct INPUT_DATA
{
    int numberOfGenres;
    int musicCount;
    int numberOfPlaylists;
    char playlists[101][101];
    char genre[101][101];
    char musicName[101][101];
    char artistName[101][101];
    float rating[101];
    float length[101];
    DATA publication[101];
};

class MUSIC
{
public:
    static void readGenre(INPUT_DATA &data);
    static void readMusic(INPUT_DATA &data, int &i);
    static void readPlaylists(INPUT_DATA &data);
    static void clearData(INPUT_DATA &data);
    static void addSongToPlylist(INPUT_DATA &data, char playlistName[101], int &songNumber);
    static void readMusicFromPlaylist(INPUT_DATA &data, int &i);
};

void MUSIC ::readPlaylists(INPUT_DATA &data)
{
    data.numberOfPlaylists = 0;
    ifstream read("data/playlists.txt");
    while (read.getline(data.playlists[data.numberOfPlaylists], 101))
    {
        ++data.numberOfPlaylists;
    }
    read.close();
}

void MUSIC ::readGenre(INPUT_DATA &data)
{
    data.numberOfGenres = 0;
    ifstream read("data/genres.txt");
    while (read.getline(data.genre[data.numberOfGenres], 101))
    {
        ++data.numberOfGenres;
    }
    read.close();
}

void MUSIC ::addSongToPlylist(INPUT_DATA &data, char playlistName[101], int &songNumber)
{
    songNumber -= 1;
    cout << "Enter the name of the playlist you want your song to go:\n> ";
    cin >> playlistName;
    char buffer[101];
    sprintf(buffer, "data/playlists/%s.txt", playlistName);
    // ifstream isIn(buffer);
    ofstream mke(buffer, std::ios::app);
    // char isInPlaylistName[101];
    // char isInPlaylistArtist[101];
    //  float hold1, hold2;
    //  int hold3, hold4, hold5;
    bool letGo = true;
    // while (isIn.getline(isInPlaylistName, 101), isIn.getline(isInPlaylistArtist, 101), isIn >> hold1 >> hold2 >> hold3 >> hold4 >> hold5)
    // {
    //     if (strstr(isInPlaylistName, data.musicName[songNumber]))
    //     {

    //         letGo = false;
    //     }
    // }
    if (letGo)
    {
        mke << data.musicName[songNumber] << "\n";
        mke << data.artistName[songNumber] << "\n";
        mke << data.rating[songNumber] << "\n";
        mke << data.length[songNumber] << "\n";
        mke << data.publication[songNumber].day << " " << data.publication[songNumber].month << " " << data.publication[songNumber].year << "\n";
    }
    else
    {
        cout << "Song already in playlist\n";
        int n;
        cin >> n;
    }
    mke.close();
}

void MUSIC ::clearData(INPUT_DATA &data)
{
    int n = 0;
    while (n < data.musicCount)
    {
        data.genre[n][0] = '\0';
        data.musicName[n][0] = '\0';
        data.artistName[n][0] = '\0';
        data.rating[n] = 0;
        data.length[n] = 0;
        data.publication[n].day = 0;
        data.publication[n].month = 0;
        data.publication[n].year = 0;
        ++n;
    }
    data.musicCount = 0;
    // data.musicName[n].clear();
    // data.artistName[n].clear();
    // data.rating[n] = 0;
    // data.length[n] = 0;
    // data.publication[n].day = 0;
    // data.publication[n].month = 0;
    // data.publication[n].year = 0;
}

void MUSIC ::readMusic(INPUT_DATA &data, int &i)
{

    char buffer[101];
    sprintf(buffer, "data/avalible_music/%s.txt", data.genre[i - 1]);
    ifstream read(buffer);
    clearData(data);
    int n = 0;
    while (read.getline(data.musicName[n], 101) && read.getline(data.artistName[n], 101) && read >> data.rating[n] && read >> data.length[n] && read >> data.publication[n].day >> data.publication[n].month >> data.publication[n].year)
    {
        read.get();
        ++n;
    }
    data.musicCount = n;
}

void MUSIC ::readMusicFromPlaylist(INPUT_DATA &data, int &i)
{
    char buffer[101];
    sprintf(buffer, "data/playlists/%s.txt", data.playlists[i - 1]);
    ifstream read(buffer);
    clearData(data);
    int n = 0;
    while (read.getline(data.musicName[n], 101) && read.getline(data.artistName[n], 101) && read >> data.rating[n] && read >> data.length[n] && read >> data.publication[n].day >> data.publication[n].month >> data.publication[n].year)
    {
        read.get();
        ++n;
    }
    data.musicCount = n;
}

#endif