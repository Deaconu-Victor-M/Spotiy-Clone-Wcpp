#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct DATA {
    unsigned int day, month, year;
};

struct INPUT_DATA {
    int numberOfGenres;
    char genre[101][101];
    char musicName[101][101];
    float rating;
    float length;
    DATA publication;
};

class MUSIC {
   public:
    static void readGenre(INPUT_DATA &data);
};

void MUSIC ::readGenre(INPUT_DATA &data) {
    data.numberOfGenres = 0;
    ifstream read("data/genres.txt");
    while (read.getline(data.genre[data.numberOfGenres], 100)) {
        ++data.numberOfGenres;
    }
    read.close();
    //cout << data.numberOfGenres << "\n";
}

#endif