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
    int mel;
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
};

void MUSIC ::readGenre(INPUT_DATA &data)
{
    data.numberOfGenres = 0;
    ifstream read("data/genres.txt");
    while (read.getline(data.genre[data.numberOfGenres], 101))
    {
        ++data.numberOfGenres;
    }
    read.close();
    // cout << data.numberOfGenres << "\n";
}

void MUSIC ::readMusic(INPUT_DATA &data, int &i)
{

    char buffer[101];
    sprintf(buffer, "data/avalible_music/%s.txt", data.genre[i - 1]);
    cout << buffer << "\n";
    ifstream read(buffer);
    read >> data.mel;
    int n = 0;
    while (n < data.mel)
    {
        read.getline(data.musicName[n], 101);
        read.getline(data.artistName[n], 101);
        read >> data.rating[n];
        read >> data.length[n];
        read >> data.publication[n].day >> data.publication[n].month >> data.publication[n].year;
    }
}

#endif