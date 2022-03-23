#include <iostream>

#include "service.hpp"
#include "ui.h"

int main() {
    bool isRunning = true;
    INPUT_DATA data;
    int choice;

    while (isRunning) {
        UI ::start();
        SERVICES ::optionInput(choice);
        switch (choice) {
            case 0:
                isRunning = false;
                break;
            case 1:
                MUSIC ::readGenre(data);
                UI ::showGenres(data);
                isRunning = false;
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
                break;
        }
    }

    return 0;
}