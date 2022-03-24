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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            UI ::clear();
            UI ::error();
            break;
        }
    }

    return 0;
}