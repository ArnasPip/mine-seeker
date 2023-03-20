//MINESWEEPER Arnas Pipinis PRIf-21/3 

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

enum ConsoleColors
{
    BlackFore = 0,
    MaroonFore = FOREGROUND_RED,
    GreenFore = FOREGROUND_GREEN,
    NavyFore = FOREGROUND_BLUE,
    TealFore = FOREGROUND_GREEN | FOREGROUND_BLUE,
    OliveFore = FOREGROUND_RED | FOREGROUND_GREEN,
    PurpleFore = FOREGROUND_RED | FOREGROUND_BLUE,
    GrayFore = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    SilverFore = FOREGROUND_INTENSITY,
    RedFore = FOREGROUND_INTENSITY | FOREGROUND_RED,
    LimeFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    BlueFore = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    AquaFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    YellowFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    FuchsiaFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    WhiteFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    MaroonBack = BACKGROUND_RED,
    BlackBack = 0,
};

class baseMap {
protected:
    int xSize, ySize, mineCount;
public:
    baseMap() :xSize(0), ySize(0), mineCount(0) {};
    virtual ~baseMap() {};
    virtual void updateBoard(int& PlayPosx, int& PlayPosy, int action, bool& first, int& flags, int& revealed, int& gaming) = 0;
    virtual void drawBoard(int& PlayPosx, int& PlayPosy, int flags) = 0;
    virtual void generateBoard(int& flags) = 0;
    virtual void operator++() = 0;
};
class easyMap : public baseMap {
private:
    char ePrivate[10][8] = { 0 };
    char ePublic[10][8] = { 0 };
public:
    easyMap() {
        mineCount = 10;
    };
    ~easyMap() {};
    void operator++() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                ePublic[i][j] = 'x';
            }
        }
    }
    void updateBoard(int& PlayPosx, int& PlayPosy, int action, bool& first, int& flags, int& revealed, int& gaming) {
        if (action == 1) {//w
            if (PlayPosy != 0) {
                PlayPosy--;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 2) {//a
            if (PlayPosx != 0) {
                PlayPosx--;
                drawBoard(PlayPosx, PlayPosy, flags);

            }
        }
        if (action == 3) {//s
            if (PlayPosy != 9) {
                PlayPosy++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 4) {//d
            if (PlayPosx != 7) {
                PlayPosx++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 5) {
            if (ePublic[PlayPosy][PlayPosx] == 'X') {
                flags++;
            }
            if (first == true) {
                while (ePrivate[PlayPosy][PlayPosx] != ' ') {
                    generateBoard(flags);
                }
                ePublic[PlayPosy][PlayPosx] = 'x';
                first = false;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                ePublic[PlayPosy][PlayPosx] = 'x';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            if (ePrivate[PlayPosy][PlayPosx] == ' ') {
                int x = PlayPosx;
                int y = PlayPosy;
                while (x != 7 && ePrivate[y][x] == ' ') {
                    x++;
                    while (y != 9 && ePrivate[y][x] == ' ') {
                        y++;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 9 && ePrivate[y][x] == ' ') {
                    y++;
                    while (x != 7 && ePrivate[y][x] == ' ') {
                        x++;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && ePrivate[y][x] == ' ') {
                    y--;
                    while (x != 7 && ePrivate[y][x] == ' ') {
                        x++;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && ePrivate[y][x] == ' ') {
                    x--;
                    while (y != 9 && ePrivate[y][x] == ' ') {
                        y++;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 9 && ePrivate[y][x] == ' ') {
                    y++;
                    while (x != 0 && ePrivate[y][x] == ' ') {
                        x--;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 7 && ePrivate[y][x] == ' ') {
                    x++;
                    while (y != 0 && ePrivate[y][x] == ' ') {
                        y--;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && ePrivate[y][x] == ' ') {
                    y--;
                    while (x != 0 && ePrivate[y][x] == ' ') {
                        x--;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && ePrivate[y][x] == ' ') {
                    x--;
                    while (y != 0 && ePrivate[y][x] == ' ') {
                        y--;
                        ePublic[y][x] = 'x';
                    }
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && ePrivate[y][x] == ' ') {
                    x--;
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && ePrivate[y][x] == ' ') {
                    y--;
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 7 && ePrivate[y][x] == ' ') {
                    x++;
                    ePublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 9 && ePrivate[y][x] == ' ') {
                    y++;
                    ePublic[y][x] = 'x';
                }
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            revealed = 0;
            bool bombs = false;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 8; j++) {
                    if (ePublic[i][j] == 'x') {
                        revealed++;
                        if (ePrivate[i][j] == '@') {
                            bombs = true;
                        }
                    }

                }
            }
            if (bombs == true) {
                gaming = 2;
            }
            else
                if (revealed == 70) {
                    gaming = 1;
                }
        }
        if (action == 6) {
            if (flags > 0) {
                flags--;
                if (ePublic[PlayPosy][PlayPosx] == 'X') {
                    ePublic[PlayPosy][PlayPosx] = '#';
                    flags += 2;
                }
                else if (ePublic[PlayPosy][PlayPosx] == 'x') {
                    flags++;
                }
                else
                    ePublic[PlayPosy][PlayPosx] = 'X';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                if (ePublic[PlayPosy][PlayPosx] == 'X') {
                    ePublic[PlayPosy][PlayPosx] = '#';
                    flags++;
                    drawBoard(PlayPosx, PlayPosy, flags);
                }
            }
        }
        if (action == 7) {
            ++(*this);
            drawBoard(PlayPosx, PlayPosy, flags);
        }
        if (action == 8) {
            generateBoard(flags);
            first = true;
            drawBoard(PlayPosx, PlayPosy, flags);
        }
    };
    void drawBoard(int& PlayPosx, int& PlayPosy, int flags) {
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (ePublic[i][j] == '#' || ePublic[i][j] == 'X') {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << ePublic[i][j];
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << "  ";
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << ePublic[i][j] << "  ";
                    }
                }
                else {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << ePrivate[i][j];
                    }
                    else if (ePrivate[i][j] == '1') {
                        SetConsoleTextAttribute(hConsole, BlueFore);
                    }
                    else if (ePrivate[i][j] == '2') {
                        SetConsoleTextAttribute(hConsole, GreenFore);
                    }
                    else if (ePrivate[i][j] == '3') {
                        SetConsoleTextAttribute(hConsole, RedFore);
                    }
                    else if (ePrivate[i][j] == '4') {
                        SetConsoleTextAttribute(hConsole, PurpleFore);
                    }
                    else if (ePrivate[i][j] == '5') {
                        SetConsoleTextAttribute(hConsole, MaroonFore);
                    }
                    else if (ePrivate[i][j] == '6') {
                        SetConsoleTextAttribute(hConsole, NavyFore);
                    }
                    else if (ePrivate[i][j] == '7') {
                        SetConsoleTextAttribute(hConsole, LimeFore);
                    }
                    else if (ePrivate[i][j] == '8') {
                        SetConsoleTextAttribute(hConsole, YellowFore);
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                    }
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, BlackBack);
                        cout << "  ";
                    }
                    else {
                        cout << ePrivate[i][j] << "  ";
                    }
                }
                if (j == 7) {
                    cout << endl;
                }
            }
        }
        SetConsoleTextAttribute(hConsole, WhiteFore);
        cout << endl;
        cout << "FLAGS: " << flags << endl;
    };
    void generateBoard(int& flags) {
        flags = mineCount;
        unsigned seed = time(0);
        srand(seed);
        vector <int> minPosX;
        vector <int> minPosY;
        int unique = 1;
        set<int>tempset;
        for (int i = 0; i < mineCount; i++) {
            tempset.insert(i);
        }
        int tempX;
        int tempY;
        while (tempset.size() > 0) {
            unique = 1;
            if (minPosX.empty() == true) {
                tempX = (rand() % 10);
                tempY = (rand() % 8);
                minPosX.push_back(tempX);
                minPosY.push_back(tempY);
            }
            while (unique > 0) {
                tempX = (rand() % 10);
                tempY = (rand() % 8);
                unique = 0;
                for (int i = 0; i < minPosX.size(); i++) {
                    for (int j = 0; j < minPosY.size(); j++) {
                        if (tempX == minPosX[i] && tempY == minPosY[i]) {
                            unique++;
                        }
                    }
                }
            }
            minPosX.push_back(tempX);
            minPosY.push_back(tempY);
            tempset.erase(tempset.begin());
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                ePublic[i][j] = '#';
                ePrivate[i][j] = ' ';
                for (int x = 0; x < mineCount; x++) {
                    if (i == minPosX[x] && j == minPosY[x]) {
                        ePrivate[i][j] = '@';
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (ePrivate[i][j] == '@') {
                    if (i == 0 && j == 0) {
                        if (ePrivate[i + 1][j + 1] == ' ') {
                            ePrivate[i + 1][j + 1] = '1';
                        }
                        else if (ePrivate[i + 1][j + 1] == '1') {
                            ePrivate[i + 1][j + 1] = '2';
                        }
                        else if (ePrivate[i + 1][j + 1] == '2') {
                            ePrivate[i + 1][j + 1] = '3';
                        }
                        else if (ePrivate[i + 1][j + 1] == '3') {
                            ePrivate[i + 1][j + 1] = '4';
                        }
                        else if (ePrivate[i + 1][j + 1] == '4') {
                            ePrivate[i + 1][j + 1] = '5';
                        }
                        else if (ePrivate[i + 1][j + 1] == '5') {
                            ePrivate[i + 1][j + 1] = '6';
                        }
                        else if (ePrivate[i + 1][j + 1] == '6') {
                            ePrivate[i + 1][j + 1] = '7';
                        }
                        else if (ePrivate[i + 1][j + 1] == '7') {
                            ePrivate[i + 1][j + 1] = '8';
                        }
                        if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 0 && j != 0 && j != 7) {
                        if (ePrivate[i + 1][j + 1] == ' ') {
                            ePrivate[i + 1][j + 1] = '1';
                        }
                        else if (ePrivate[i + 1][j + 1] == '1') {
                            ePrivate[i + 1][j + 1] = '2';
                        }
                        else if (ePrivate[i + 1][j + 1] == '2') {
                            ePrivate[i + 1][j + 1] = '3';
                        }
                        else if (ePrivate[i + 1][j + 1] == '3') {
                            ePrivate[i + 1][j + 1] = '4';
                        }
                        else if (ePrivate[i + 1][j + 1] == '4') {
                            ePrivate[i + 1][j + 1] = '5';
                        }
                        else if (ePrivate[i + 1][j + 1] == '5') {
                            ePrivate[i + 1][j + 1] = '6';
                        }
                        else if (ePrivate[i + 1][j + 1] == '6') {
                            ePrivate[i + 1][j + 1] = '7';
                        }
                        else if (ePrivate[i + 1][j + 1] == '7') {
                            ePrivate[i + 1][j + 1] = '8';
                        }
                        if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j] = '8';
                        }
                        if (ePrivate[i + 1][j - 1] == ' ') {
                            ePrivate[i + 1][j - 1] = '1';
                        }
                        else if (ePrivate[i + 1][j - 1] == '1') {
                            ePrivate[i + 1][j - 1] = '2';
                        }
                        else if (ePrivate[i + 1][j - 1] == '2') {
                            ePrivate[i + 1][j - 1] = '3';
                        }
                        else if (ePrivate[i + 1][j - 1] == '3') {
                            ePrivate[i + 1][j - 1] = '4';
                        }
                        else if (ePrivate[i + 1][j - 1] == '4') {
                            ePrivate[i + 1][j - 1] = '5';
                        }
                        else if (ePrivate[i + 1][j - 1] == '5') {
                            ePrivate[i + 1][j - 1] = '6';
                        }
                        else if (ePrivate[i + 1][j - 1] == '6') {
                            ePrivate[i + 1][j - 1] = '7';
                        }
                        else if (ePrivate[i + 1][j - 1] == '7') {
                            ePrivate[i + 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                    }
                    if (i != 0 && j == 0 && i != 9) {
                        if (ePrivate[i + 1][j + 1] == ' ') {
                            ePrivate[i + 1][j + 1] = '1';
                        }
                        else if (ePrivate[i + 1][j + 1] == '1') {
                            ePrivate[i + 1][j + 1] = '2';
                        }
                        else if (ePrivate[i + 1][j + 1] == '2') {
                            ePrivate[i + 1][j + 1] = '3';
                        }
                        else if (ePrivate[i + 1][j + 1] == '3') {
                            ePrivate[i + 1][j + 1] = '4';
                        }
                        else if (ePrivate[i + 1][j + 1] == '4') {
                            ePrivate[i + 1][j + 1] = '5';
                        }
                        else if (ePrivate[i + 1][j + 1] == '5') {
                            ePrivate[i + 1][j + 1] = '6';
                        }
                        else if (ePrivate[i + 1][j + 1] == '6') {
                            ePrivate[i + 1][j + 1] = '7';
                        }
                        else if (ePrivate[i + 1][j + 1] == '7') {
                            ePrivate[i + 1][j + 1] = '8';
                        }
                        if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j] = '8';
                        }
                        if (ePrivate[i - 1][j + 1] == ' ') {
                            ePrivate[i - 1][j + 1] = '1';
                        }
                        else if (ePrivate[i - 1][j + 1] == '1') {
                            ePrivate[i - 1][j + 1] = '2';
                        }
                        else if (ePrivate[i - 1][j + 1] == '2') {
                            ePrivate[i - 1][j + 1] = '3';
                        }
                        else if (ePrivate[i - 1][j + 1] == '3') {
                            ePrivate[i - 1][j + 1] = '4';
                        }
                        else if (ePrivate[i - 1][j + 1] == '4') {
                            ePrivate[i - 1][j + 1] = '5';
                        }
                        else if (ePrivate[i - 1][j + 1] == '5') {
                            ePrivate[i - 1][j + 1] = '6';
                        }
                        else if (ePrivate[i - 1][j + 1] == '6') {
                            ePrivate[i - 1][j + 1] = '7';
                        }
                        else if (ePrivate[i - 1][j + 1] == '7') {
                            ePrivate[i - 1][j + 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }
                    }
                    if (i == 9 && j == 7) {
                        if (ePrivate[i - 1][j - 1] == ' ') {
                            ePrivate[i - 1][j - 1] = '1';
                        }
                        else if (ePrivate[i - 1][j - 1] == '1') {
                            ePrivate[i - 1][j - 1] = '2';
                        }
                        else if (ePrivate[i - 1][j - 1] == '2') {
                            ePrivate[i - 1][j - 1] = '3';
                        }
                        else if (ePrivate[i - 1][j - 1] == '3') {
                            ePrivate[i - 1][j - 1] = '4';
                        }
                        else if (ePrivate[i - 1][j - 1] == '4') {
                            ePrivate[i - 1][j - 1] = '5';
                        }
                        else if (ePrivate[i - 1][j - 1] == '5') {
                            ePrivate[i - 1][j - 1] = '6';
                        }
                        else if (ePrivate[i - 1][j - 1] == '6') {
                            ePrivate[i - 1][j - 1] = '7';
                        }
                        else if (ePrivate[i - 1][j - 1] == '7') {
                            ePrivate[i - 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 9 && j == 7 && i != 0) {
                        if (ePrivate[i - 1][j - 1] == ' ') {
                            ePrivate[i - 1][j - 1] = '1';
                        }
                        else if (ePrivate[i - 1][j - 1] == '1') {
                            ePrivate[i - 1][j - 1] = '2';
                        }
                        else if (ePrivate[i - 1][j - 1] == '2') {
                            ePrivate[i - 1][j - 1] = '3';
                        }
                        else if (ePrivate[i - 1][j - 1] == '3') {
                            ePrivate[i - 1][j - 1] = '4';
                        }
                        else if (ePrivate[i - 1][j - 1] == '4') {
                            ePrivate[i - 1][j - 1] = '5';
                        }
                        else if (ePrivate[i - 1][j - 1] == '5') {
                            ePrivate[i - 1][j - 1] = '6';
                        }
                        else if (ePrivate[i - 1][j - 1] == '6') {
                            ePrivate[i - 1][j - 1] = '7';
                        }
                        else if (ePrivate[i - 1][j - 1] == '7') {
                            ePrivate[i - 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j - 1] == ' ') {
                            ePrivate[i + 1][j - 1] = '1';
                        }
                        else if (ePrivate[i + 1][j - 1] == '1') {
                            ePrivate[i + 1][j - 1] = '2';
                        }
                        else if (ePrivate[i + 1][j - 1] == '2') {
                            ePrivate[i + 1][j - 1] = '3';
                        }
                        else if (ePrivate[i + 1][j - 1] == '3') {
                            ePrivate[i + 1][j - 1] = '4';
                        }
                        else if (ePrivate[i + 1][j - 1] == '4') {
                            ePrivate[i + 1][j - 1] = '5';
                        }
                        else if (ePrivate[i + 1][j - 1] == '5') {
                            ePrivate[i + 1][j - 1] = '6';
                        }
                        else if (ePrivate[i + 1][j - 1] == '6') {
                            ePrivate[i + 1][j - 1] = '7';
                        }
                        else if (ePrivate[i + 1][j - 1] == '7') {
                            ePrivate[i + 1][j - 1] = '8';
                        }
                    }
                    if (i == 9 && j != 7 && j != 0) {
                        if (ePrivate[i - 1][j - 1] == ' ') {
                            ePrivate[i - 1][j - 1] = '1';
                        }
                        else if (ePrivate[i - 1][j - 1] == '1') {
                            ePrivate[i - 1][j - 1] = '2';
                        }
                        else if (ePrivate[i - 1][j - 1] == '2') {
                            ePrivate[i - 1][j - 1] = '3';
                        }
                        else if (ePrivate[i - 1][j - 1] == '3') {
                            ePrivate[i - 1][j - 1] = '4';
                        }
                        else if (ePrivate[i - 1][j - 1] == '4') {
                            ePrivate[i - 1][j - 1] = '5';
                        }
                        else if (ePrivate[i - 1][j - 1] == '5') {
                            ePrivate[i - 1][j - 1] = '6';
                        }
                        else if (ePrivate[i - 1][j - 1] == '6') {
                            ePrivate[i - 1][j - 1] = '7';
                        }
                        else if (ePrivate[i - 1][j - 1] == '7') {
                            ePrivate[i - 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i - 1][j + 1] == ' ') {
                            ePrivate[i - 1][j + 1] = '1';
                        }
                        else if (ePrivate[i - 1][j + 1] == '1') {
                            ePrivate[i - 1][j + 1] = '2';
                        }
                        else if (ePrivate[i - 1][j + 1] == '2') {
                            ePrivate[i - 1][j + 1] = '3';
                        }
                        else if (ePrivate[i - 1][j + 1] == '3') {
                            ePrivate[i - 1][j + 1] = '4';
                        }
                        else if (ePrivate[i - 1][j + 1] == '4') {
                            ePrivate[i - 1][j + 1] = '5';
                        }
                        else if (ePrivate[i - 1][j + 1] == '5') {
                            ePrivate[i - 1][j + 1] = '6';
                        }
                        else if (ePrivate[i - 1][j + 1] == '6') {
                            ePrivate[i - 1][j + 1] = '7';
                        }
                        else if (ePrivate[i - 1][j + 1] == '7') {
                            ePrivate[i - 1][j + 1] = '8';
                        }
                    }
                    if (i == 0 && j == 7) {
                        if (ePrivate[i + 1][j - 1] == ' ') {
                            ePrivate[i + 1][j - 1] = '1';
                        }
                        else if (ePrivate[i + 1][j - 1] == '1') {
                            ePrivate[i + 1][j - 1] = '2';
                        }
                        else if (ePrivate[i + 1][j - 1] == '2') {
                            ePrivate[i + 1][j - 1] = '3';
                        }
                        else if (ePrivate[i + 1][j - 1] == '3') {
                            ePrivate[i + 1][j - 1] = '4';
                        }
                        else if (ePrivate[i + 1][j - 1] == '4') {
                            ePrivate[i + 1][j - 1] = '5';
                        }
                        else if (ePrivate[i + 1][j - 1] == '5') {
                            ePrivate[i + 1][j - 1] = '6';
                        }
                        else if (ePrivate[i + 1][j - 1] == '6') {
                            ePrivate[i + 1][j - 1] = '7';
                        }
                        else if (ePrivate[i + 1][j - 1] == '7') {
                            ePrivate[i + 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                        if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 9 && j == 0) {
                        if (ePrivate[i - 1][j + 1] == ' ') {
                            ePrivate[i - 1][j + 1] = '1';
                        }
                        else if (ePrivate[i - 1][j + 1] == '1') {
                            ePrivate[i - 1][j + 1] = '2';
                        }
                        else if (ePrivate[i - 1][j + 1] == '2') {
                            ePrivate[i - 1][j + 1] = '3';
                        }
                        else if (ePrivate[i - 1][j + 1] == '3') {
                            ePrivate[i - 1][j + 1] = '4';
                        }
                        else if (ePrivate[i - 1][j + 1] == '4') {
                            ePrivate[i - 1][j + 1] = '5';
                        }
                        else if (ePrivate[i - 1][j + 1] == '5') {
                            ePrivate[i - 1][j + 1] = '6';
                        }
                        else if (ePrivate[i - 1][j + 1] == '6') {
                            ePrivate[i - 1][j + 1] = '7';
                        }
                        else if (ePrivate[i - 1][j + 1] == '7') {
                            ePrivate[i - 1][j + 1] = '8';
                        }
                        if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 0 && i != 9 && j != 0 && j != 7) {
                        if (ePrivate[i + 1][j + 1] == ' ') {
                            ePrivate[i + 1][j + 1] = '1';
                        }
                        else if (ePrivate[i + 1][j + 1] == '1') {
                            ePrivate[i + 1][j + 1] = '2';
                        }
                        else if (ePrivate[i + 1][j + 1] == '2') {
                            ePrivate[i + 1][j + 1] = '3';
                        }
                        else if (ePrivate[i + 1][j + 1] == '3') {
                            ePrivate[i + 1][j + 1] = '4';
                        }
                        else if (ePrivate[i + 1][j + 1] == '4') {
                            ePrivate[i + 1][j + 1] = '5';
                        }
                        else if (ePrivate[i + 1][j + 1] == '5') {
                            ePrivate[i + 1][j + 1] = '6';
                        }
                        else if (ePrivate[i + 1][j + 1] == '6') {
                            ePrivate[i + 1][j + 1] = '7';
                        }
                        else if (ePrivate[i + 1][j + 1] == '7') {
                            ePrivate[i + 1][j + 1] = '8';
                        }
                        if (ePrivate[i][j + 1] == ' ') {
                            ePrivate[i][j + 1] = '1';
                        }
                        else if (ePrivate[i][j + 1] == '1') {
                            ePrivate[i][j + 1] = '2';
                        }
                        else if (ePrivate[i][j + 1] == '2') {
                            ePrivate[i][j + 1] = '3';
                        }
                        else if (ePrivate[i][j + 1] == '3') {
                            ePrivate[i][j + 1] = '4';
                        }
                        else if (ePrivate[i][j + 1] == '4') {
                            ePrivate[i][j + 1] = '5';
                        }
                        else if (ePrivate[i][j + 1] == '5') {
                            ePrivate[i][j + 1] = '6';
                        }
                        else if (ePrivate[i][j + 1] == '6') {
                            ePrivate[i][j + 1] = '7';
                        }
                        else if (ePrivate[i][j + 1] == '7') {
                            ePrivate[i][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j] == ' ') {
                            ePrivate[i + 1][j] = '1';
                        }
                        else if (ePrivate[i + 1][j] == '1') {
                            ePrivate[i + 1][j] = '2';
                        }
                        else if (ePrivate[i + 1][j] == '2') {
                            ePrivate[i + 1][j] = '3';
                        }
                        else if (ePrivate[i + 1][j] == '3') {
                            ePrivate[i + 1][j] = '4';
                        }
                        else if (ePrivate[i + 1][j] == '4') {
                            ePrivate[i + 1][j] = '5';
                        }
                        else if (ePrivate[i + 1][j] == '5') {
                            ePrivate[i + 1][j] = '6';
                        }
                        else if (ePrivate[i + 1][j] == '6') {
                            ePrivate[i + 1][j] = '7';
                        }
                        else if (ePrivate[i + 1][j] == '7') {
                            ePrivate[i + 1][j] = '8';
                        }
                        if (ePrivate[i - 1][j - 1] == ' ') {
                            ePrivate[i - 1][j - 1] = '1';
                        }
                        else if (ePrivate[i - 1][j - 1] == '1') {
                            ePrivate[i - 1][j - 1] = '2';
                        }
                        else if (ePrivate[i - 1][j - 1] == '2') {
                            ePrivate[i - 1][j - 1] = '3';
                        }
                        else if (ePrivate[i - 1][j - 1] == '3') {
                            ePrivate[i - 1][j - 1] = '4';
                        }
                        else if (ePrivate[i - 1][j - 1] == '4') {
                            ePrivate[i - 1][j - 1] = '5';
                        }
                        else if (ePrivate[i - 1][j - 1] == '5') {
                            ePrivate[i - 1][j - 1] = '6';
                        }
                        else if (ePrivate[i - 1][j - 1] == '6') {
                            ePrivate[i - 1][j - 1] = '7';
                        }
                        else if (ePrivate[i - 1][j - 1] == '7') {
                            ePrivate[i - 1][j - 1] = '8';
                        }
                        if (ePrivate[i][j - 1] == ' ') {
                            ePrivate[i][j - 1] = '1';
                        }
                        else if (ePrivate[i][j - 1] == '1') {
                            ePrivate[i][j - 1] = '2';
                        }
                        else if (ePrivate[i][j - 1] == '2') {
                            ePrivate[i][j - 1] = '3';
                        }
                        else if (ePrivate[i][j - 1] == '3') {
                            ePrivate[i][j - 1] = '4';
                        }
                        else if (ePrivate[i][j - 1] == '4') {
                            ePrivate[i][j - 1] = '5';
                        }
                        else if (ePrivate[i][j - 1] == '5') {
                            ePrivate[i][j - 1] = '6';
                        }
                        else if (ePrivate[i][j - 1] == '6') {
                            ePrivate[i][j - 1] = '7';
                        }
                        else if (ePrivate[i][j - 1] == '7') {
                            ePrivate[i][j - 1] = '8';
                        }
                        if (ePrivate[i - 1][j] == ' ') {
                            ePrivate[i - 1][j] = '1';
                        }
                        else if (ePrivate[i - 1][j] == '1') {
                            ePrivate[i - 1][j] = '2';
                        }
                        else if (ePrivate[i - 1][j] == '2') {
                            ePrivate[i - 1][j] = '3';
                        }
                        else if (ePrivate[i - 1][j] == '3') {
                            ePrivate[i - 1][j] = '4';
                        }
                        else if (ePrivate[i - 1][j] == '4') {
                            ePrivate[i - 1][j] = '5';
                        }
                        else if (ePrivate[i - 1][j] == '5') {
                            ePrivate[i - 1][j] = '6';
                        }
                        else if (ePrivate[i - 1][j] == '6') {
                            ePrivate[i - 1][j] = '7';
                        }
                        else if (ePrivate[i - 1][j] == '7') {
                            ePrivate[i - 1][j] = '8';
                        }
                        if (ePrivate[i - 1][j + 1] == ' ') {
                            ePrivate[i - 1][j + 1] = '1';
                        }
                        else if (ePrivate[i - 1][j + 1] == '1') {
                            ePrivate[i - 1][j + 1] = '2';
                        }
                        else if (ePrivate[i - 1][j + 1] == '2') {
                            ePrivate[i - 1][j + 1] = '3';
                        }
                        else if (ePrivate[i - 1][j + 1] == '3') {
                            ePrivate[i - 1][j + 1] = '4';
                        }
                        else if (ePrivate[i - 1][j + 1] == '4') {
                            ePrivate[i - 1][j + 1] = '5';
                        }
                        else if (ePrivate[i - 1][j + 1] == '5') {
                            ePrivate[i - 1][j + 1] = '6';
                        }
                        else if (ePrivate[i - 1][j + 1] == '6') {
                            ePrivate[i - 1][j + 1] = '7';
                        }
                        else if (ePrivate[i - 1][j + 1] == '7') {
                            ePrivate[i - 1][j + 1] = '8';
                        }
                        if (ePrivate[i + 1][j - 1] == ' ') {
                            ePrivate[i + 1][j - 1] = '1';
                        }
                        else if (ePrivate[i + 1][j - 1] == '1') {
                            ePrivate[i + 1][j - 1] = '2';
                        }
                        else if (ePrivate[i + 1][j - 1] == '2') {
                            ePrivate[i + 1][j - 1] = '3';
                        }
                        else if (ePrivate[i + 1][j - 1] == '3') {
                            ePrivate[i + 1][j - 1] = '4';
                        }
                        else if (ePrivate[i + 1][j - 1] == '4') {
                            ePrivate[i + 1][j - 1] = '5';
                        }
                        else if (ePrivate[i + 1][j - 1] == '5') {
                            ePrivate[i + 1][j - 1] = '6';
                        }
                        else if (ePrivate[i + 1][j - 1] == '6') {
                            ePrivate[i + 1][j - 1] = '7';
                        }
                        else if (ePrivate[i + 1][j - 1] == '7') {
                            ePrivate[i + 1][j - 1] = '8';
                        }
                    }
                }
            }
        }
    }
};
class mediumMap : public baseMap {
private:
    char mPrivate[18][14] = { 0 };
    char mPublic[18][14] = { 0 };
public:
    mediumMap() {
        mineCount = 40;
    };
    ~mediumMap() {};
    void operator++() {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 14; j++) {
                mPublic[i][j] = 'x';
            }
        }
    }
    void updateBoard(int& PlayPosx, int& PlayPosy, int action, bool& first, int& flags, int& revealed, int& gaming) {
        if (action == 1) {//w
            if (PlayPosy != 0) {
                PlayPosy--;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 2) {//a
            if (PlayPosx != 0) {
                PlayPosx--;
                drawBoard(PlayPosx, PlayPosy, flags);

            }
        }
        if (action == 3) {//s
            if (PlayPosy != 17) {
                PlayPosy++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 4) {//d
            if (PlayPosx != 13) {
                PlayPosx++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 5) {
            if (mPublic[PlayPosy][PlayPosx] == 'X') {
                flags++;
            }
            if (first == true) {
                while (mPrivate[PlayPosy][PlayPosx] != ' ') {
                    generateBoard(flags);
                }
                mPublic[PlayPosy][PlayPosx] = 'x';
                first = false;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                mPublic[PlayPosy][PlayPosx] = 'x';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            if (mPrivate[PlayPosy][PlayPosx] == ' ') {
                int x = PlayPosx;
                int y = PlayPosy;
                while (x != 13 && mPrivate[y][x] == ' ') {
                    x++;
                    while (y != 17 && mPrivate[y][x] == ' ') {
                        y++;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 17 && mPrivate[y][x] == ' ') {
                    y++;
                    while (x != 13 && mPrivate[y][x] == ' ') {
                        x++;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && mPrivate[y][x] == ' ') {
                    y--;
                    while (x != 13 && mPrivate[y][x] == ' ') {
                        x++;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && mPrivate[y][x] == ' ') {
                    x--;
                    while (y != 17 && mPrivate[y][x] == ' ') {
                        y++;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 17 && mPrivate[y][x] == ' ') {
                    y++;
                    while (x != 0 && mPrivate[y][x] == ' ') {
                        x--;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 13 && mPrivate[y][x] == ' ') {
                    x++;
                    while (y != 0 && mPrivate[y][x] == ' ') {
                        y--;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && mPrivate[y][x] == ' ') {
                    y--;
                    while (x != 0 && mPrivate[y][x] == ' ') {
                        x--;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && mPrivate[y][x] == ' ') {
                    x--;
                    while (y != 0 && mPrivate[y][x] == ' ') {
                        y--;
                        mPublic[y][x] = 'x';
                    }
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && mPrivate[y][x] == ' ') {
                    x--;
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && mPrivate[y][x] == ' ') {
                    y--;
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 13 && mPrivate[y][x] == ' ') {
                    x++;
                    mPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 17 && mPrivate[y][x] == ' ') {
                    y++;
                    mPublic[y][x] = 'x';
                }
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            revealed = 0;
            bool bombs = false;
            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 14; j++) {
                    if (mPublic[i][j] == 'x') {
                        revealed++;
                        if (mPrivate[i][j] == '@') {
                            bombs = true;
                        }
                    }

                }
            }
            if (bombs == true) {
                gaming = 2;
            }
            else
                if (revealed == 212) {
                    gaming = 1;
                }
        }
        if (action == 6) {
            if (flags > 0) {
                flags--;
                if (mPublic[PlayPosy][PlayPosx] == 'X') {
                    mPublic[PlayPosy][PlayPosx] = '#';
                    flags += 2;
                }
                else if (mPublic[PlayPosy][PlayPosx] == 'x') {
                    flags++;
                }
                else
                    mPublic[PlayPosy][PlayPosx] = 'X';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                if (mPublic[PlayPosy][PlayPosx] == 'X') {
                    mPublic[PlayPosy][PlayPosx] = '#';
                    flags++;
                    drawBoard(PlayPosx, PlayPosy, flags);
                }
            }
        }
        if (action == 7) {
            ++(*this);
            drawBoard(PlayPosx, PlayPosy, flags);
        }
        if (action == 8) {
            generateBoard(flags);
            first = true;
            drawBoard(PlayPosx, PlayPosy, flags);

        }
    };
    void drawBoard(int& PlayPosx, int& PlayPosy, int flags) {
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 14; j++) {
                if (mPublic[i][j] == '#' || mPublic[i][j] == 'X') {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << mPublic[i][j];
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << "  ";
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << mPublic[i][j] << "  ";
                    }
                }
                else {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << mPrivate[i][j];
                    }
                    else if (mPrivate[i][j] == '1') {
                        SetConsoleTextAttribute(hConsole, BlueFore);
                    }
                    else if (mPrivate[i][j] == '2') {
                        SetConsoleTextAttribute(hConsole, GreenFore);
                    }
                    else if (mPrivate[i][j] == '3') {
                        SetConsoleTextAttribute(hConsole, RedFore);
                    }
                    else if (mPrivate[i][j] == '4') {
                        SetConsoleTextAttribute(hConsole, PurpleFore);
                    }
                    else if (mPrivate[i][j] == '5') {
                        SetConsoleTextAttribute(hConsole, MaroonFore);
                    }
                    else if (mPrivate[i][j] == '6') {
                        SetConsoleTextAttribute(hConsole, NavyFore);
                    }
                    else if (mPrivate[i][j] == '7') {
                        SetConsoleTextAttribute(hConsole, LimeFore);
                    }
                    else if (mPrivate[i][j] == '8') {
                        SetConsoleTextAttribute(hConsole, YellowFore);
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                    }
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, BlackBack);
                        cout << "  ";
                    }
                    else {
                        cout << mPrivate[i][j] << "  ";
                    }
                }
                if (j == 13) {
                    cout << endl;
                }
            }
        }
        SetConsoleTextAttribute(hConsole, WhiteFore);
        cout << endl;
        cout << "FLAGS: " << flags << endl;
    };
    void generateBoard(int& flags) {
        flags = mineCount;
        unsigned seed = time(0);
        srand(seed);
        vector <int> minPosX;
        vector <int> minPosY;
        int unique = 1;
        set<int>tempset;
        for (int i = 0; i < mineCount; i++) {
            tempset.insert(i);
        }
        int tempX;
        int tempY;
        while (tempset.size() > 0) {
            unique = 1;
            if (minPosX.empty() == true) {
                tempX = (rand() % 18);
                tempY = (rand() % 14);
                minPosX.push_back(tempX);
                minPosY.push_back(tempY);
            }
            while (unique > 0) {
                tempX = (rand() % 18);
                tempY = (rand() % 14);
                unique = 0;
                for (int i = 0; i < minPosX.size(); i++) {
                    for (int j = 0; j < minPosY.size(); j++) {
                        if (tempX == minPosX[i] && tempY == minPosY[i]) {
                            unique++;
                        }
                    }
                }
            }
            minPosX.push_back(tempX);
            minPosY.push_back(tempY);
            tempset.erase(tempset.begin());
        }
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 14; j++) {
                mPublic[i][j] = '#';
                mPrivate[i][j] = ' ';
                for (int x = 0; x < mineCount; x++) {
                    if (i == minPosX[x] && j == minPosY[x]) {
                        mPrivate[i][j] = '@';
                    }
                }
            }
        }
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 14; j++) {
                if (mPrivate[i][j] == '@') {
                    if (i == 0 && j == 0) {
                        if (mPrivate[i + 1][j + 1] == ' ') {
                            mPrivate[i + 1][j + 1] = '1';
                        }
                        else if (mPrivate[i + 1][j + 1] == '1') {
                            mPrivate[i + 1][j + 1] = '2';
                        }
                        else if (mPrivate[i + 1][j + 1] == '2') {
                            mPrivate[i + 1][j + 1] = '3';
                        }
                        else if (mPrivate[i + 1][j + 1] == '3') {
                            mPrivate[i + 1][j + 1] = '4';
                        }
                        else if (mPrivate[i + 1][j + 1] == '4') {
                            mPrivate[i + 1][j + 1] = '5';
                        }
                        else if (mPrivate[i + 1][j + 1] == '5') {
                            mPrivate[i + 1][j + 1] = '6';
                        }
                        else if (mPrivate[i + 1][j + 1] == '6') {
                            mPrivate[i + 1][j + 1] = '7';
                        }
                        else if (mPrivate[i + 1][j + 1] == '7') {
                            mPrivate[i + 1][j + 1] = '8';
                        }
                        if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 0 && j != 0 && j != 13) {
                        if (mPrivate[i + 1][j + 1] == ' ') {
                            mPrivate[i + 1][j + 1] = '1';
                        }
                        else if (mPrivate[i + 1][j + 1] == '1') {
                            mPrivate[i + 1][j + 1] = '2';
                        }
                        else if (mPrivate[i + 1][j + 1] == '2') {
                            mPrivate[i + 1][j + 1] = '3';
                        }
                        else if (mPrivate[i + 1][j + 1] == '3') {
                            mPrivate[i + 1][j + 1] = '4';
                        }
                        else if (mPrivate[i + 1][j + 1] == '4') {
                            mPrivate[i + 1][j + 1] = '5';
                        }
                        else if (mPrivate[i + 1][j + 1] == '5') {
                            mPrivate[i + 1][j + 1] = '6';
                        }
                        else if (mPrivate[i + 1][j + 1] == '6') {
                            mPrivate[i + 1][j + 1] = '7';
                        }
                        else if (mPrivate[i + 1][j + 1] == '7') {
                            mPrivate[i + 1][j + 1] = '8';
                        }
                        if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j] = '8';
                        }
                        if (mPrivate[i + 1][j - 1] == ' ') {
                            mPrivate[i + 1][j - 1] = '1';
                        }
                        else if (mPrivate[i + 1][j - 1] == '1') {
                            mPrivate[i + 1][j - 1] = '2';
                        }
                        else if (mPrivate[i + 1][j - 1] == '2') {
                            mPrivate[i + 1][j - 1] = '3';
                        }
                        else if (mPrivate[i + 1][j - 1] == '3') {
                            mPrivate[i + 1][j - 1] = '4';
                        }
                        else if (mPrivate[i + 1][j - 1] == '4') {
                            mPrivate[i + 1][j - 1] = '5';
                        }
                        else if (mPrivate[i + 1][j - 1] == '5') {
                            mPrivate[i + 1][j - 1] = '6';
                        }
                        else if (mPrivate[i + 1][j - 1] == '6') {
                            mPrivate[i + 1][j - 1] = '7';
                        }
                        else if (mPrivate[i + 1][j - 1] == '7') {
                            mPrivate[i + 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                    }
                    if (i != 0 && j == 0 && i != 17) {
                        if (mPrivate[i + 1][j + 1] == ' ') {
                            mPrivate[i + 1][j + 1] = '1';
                        }
                        else if (mPrivate[i + 1][j + 1] == '1') {
                            mPrivate[i + 1][j + 1] = '2';
                        }
                        else if (mPrivate[i + 1][j + 1] == '2') {
                            mPrivate[i + 1][j + 1] = '3';
                        }
                        else if (mPrivate[i + 1][j + 1] == '3') {
                            mPrivate[i + 1][j + 1] = '4';
                        }
                        else if (mPrivate[i + 1][j + 1] == '4') {
                            mPrivate[i + 1][j + 1] = '5';
                        }
                        else if (mPrivate[i + 1][j + 1] == '5') {
                            mPrivate[i + 1][j + 1] = '6';
                        }
                        else if (mPrivate[i + 1][j + 1] == '6') {
                            mPrivate[i + 1][j + 1] = '7';
                        }
                        else if (mPrivate[i + 1][j + 1] == '7') {
                            mPrivate[i + 1][j + 1] = '8';
                        }
                        if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j] = '8';
                        }
                        if (mPrivate[i - 1][j + 1] == ' ') {
                            mPrivate[i - 1][j + 1] = '1';
                        }
                        else if (mPrivate[i - 1][j + 1] == '1') {
                            mPrivate[i - 1][j + 1] = '2';
                        }
                        else if (mPrivate[i - 1][j + 1] == '2') {
                            mPrivate[i - 1][j + 1] = '3';
                        }
                        else if (mPrivate[i - 1][j + 1] == '3') {
                            mPrivate[i - 1][j + 1] = '4';
                        }
                        else if (mPrivate[i - 1][j + 1] == '4') {
                            mPrivate[i - 1][j + 1] = '5';
                        }
                        else if (mPrivate[i - 1][j + 1] == '5') {
                            mPrivate[i - 1][j + 1] = '6';
                        }
                        else if (mPrivate[i - 1][j + 1] == '6') {
                            mPrivate[i - 1][j + 1] = '7';
                        }
                        else if (mPrivate[i - 1][j + 1] == '7') {
                            mPrivate[i - 1][j + 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i == 17 && j == 13) {
                        if (mPrivate[i - 1][j - 1] == ' ') {
                            mPrivate[i - 1][j - 1] = '1';
                        }
                        else if (mPrivate[i - 1][j - 1] == '1') {
                            mPrivate[i - 1][j - 1] = '2';
                        }
                        else if (mPrivate[i - 1][j - 1] == '2') {
                            mPrivate[i - 1][j - 1] = '3';
                        }
                        else if (mPrivate[i - 1][j - 1] == '3') {
                            mPrivate[i - 1][j - 1] = '4';
                        }
                        else if (mPrivate[i - 1][j - 1] == '4') {
                            mPrivate[i - 1][j - 1] = '5';
                        }
                        else if (mPrivate[i - 1][j - 1] == '5') {
                            mPrivate[i - 1][j - 1] = '6';
                        }
                        else if (mPrivate[i - 1][j - 1] == '6') {
                            mPrivate[i - 1][j - 1] = '7';
                        }
                        else if (mPrivate[i - 1][j - 1] == '7') {
                            mPrivate[i - 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 17 && j == 13 && i != 0) {
                        if (mPrivate[i - 1][j - 1] == ' ') {
                            mPrivate[i - 1][j - 1] = '1';
                        }
                        else if (mPrivate[i - 1][j - 1] == '1') {
                            mPrivate[i - 1][j - 1] = '2';
                        }
                        else if (mPrivate[i - 1][j - 1] == '2') {
                            mPrivate[i - 1][j - 1] = '3';
                        }
                        else if (mPrivate[i - 1][j - 1] == '3') {
                            mPrivate[i - 1][j - 1] = '4';
                        }
                        else if (mPrivate[i - 1][j - 1] == '4') {
                            mPrivate[i - 1][j - 1] = '5';
                        }
                        else if (mPrivate[i - 1][j - 1] == '5') {
                            mPrivate[i - 1][j - 1] = '6';
                        }
                        else if (mPrivate[i - 1][j - 1] == '6') {
                            mPrivate[i - 1][j - 1] = '7';
                        }
                        else if (mPrivate[i - 1][j - 1] == '7') {
                            mPrivate[i - 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j - 1] == ' ') {
                            mPrivate[i + 1][j - 1] = '1';
                        }
                        else if (mPrivate[i + 1][j - 1] == '1') {
                            mPrivate[i + 1][j - 1] = '2';
                        }
                        else if (mPrivate[i + 1][j - 1] == '2') {
                            mPrivate[i + 1][j - 1] = '3';
                        }
                        else if (mPrivate[i + 1][j - 1] == '3') {
                            mPrivate[i + 1][j - 1] = '4';
                        }
                        else if (mPrivate[i + 1][j - 1] == '4') {
                            mPrivate[i + 1][j - 1] = '5';
                        }
                        else if (mPrivate[i + 1][j - 1] == '5') {
                            mPrivate[i + 1][j - 1] = '6';
                        }
                        else if (mPrivate[i + 1][j - 1] == '6') {
                            mPrivate[i + 1][j - 1] = '7';
                        }
                        else if (mPrivate[i + 1][j - 1] == '7') {
                            mPrivate[i + 1][j - 1] = '8';
                        }
                    }
                    if (i == 17 && j != 13 && j != 0) {
                        if (mPrivate[i - 1][j - 1] == ' ') {
                            mPrivate[i - 1][j - 1] = '1';
                        }
                        else if (mPrivate[i - 1][j - 1] == '1') {
                            mPrivate[i - 1][j - 1] = '2';
                        }
                        else if (mPrivate[i - 1][j - 1] == '2') {
                            mPrivate[i - 1][j - 1] = '3';
                        }
                        else if (mPrivate[i - 1][j - 1] == '3') {
                            mPrivate[i - 1][j - 1] = '4';
                        }
                        else if (mPrivate[i - 1][j - 1] == '4') {
                            mPrivate[i - 1][j - 1] = '5';
                        }
                        else if (mPrivate[i - 1][j - 1] == '5') {
                            mPrivate[i - 1][j - 1] = '6';
                        }
                        else if (mPrivate[i - 1][j - 1] == '6') {
                            mPrivate[i - 1][j - 1] = '7';
                        }
                        else if (mPrivate[i - 1][j - 1] == '7') {
                            mPrivate[i - 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i - 1][j + 1] == ' ') {
                            mPrivate[i - 1][j + 1] = '1';
                        }
                        else if (mPrivate[i - 1][j + 1] == '1') {
                            mPrivate[i - 1][j + 1] = '2';
                        }
                        else if (mPrivate[i - 1][j + 1] == '2') {
                            mPrivate[i - 1][j + 1] = '3';
                        }
                        else if (mPrivate[i - 1][j + 1] == '3') {
                            mPrivate[i - 1][j + 1] = '4';
                        }
                        else if (mPrivate[i - 1][j + 1] == '4') {
                            mPrivate[i - 1][j + 1] = '5';
                        }
                        else if (mPrivate[i - 1][j + 1] == '5') {
                            mPrivate[i - 1][j + 1] = '6';
                        }
                        else if (mPrivate[i - 1][j + 1] == '6') {
                            mPrivate[i - 1][j + 1] = '7';
                        }
                        else if (mPrivate[i - 1][j + 1] == '7') {
                            mPrivate[i - 1][j + 1] = '8';
                        }
                    }
                    if (i == 0 && j == 13) {
                        if (mPrivate[i + 1][j - 1] == ' ') {
                            mPrivate[i + 1][j - 1] = '1';
                        }
                        else if (mPrivate[i + 1][j - 1] == '1') {
                            mPrivate[i + 1][j - 1] = '2';
                        }
                        else if (mPrivate[i + 1][j - 1] == '2') {
                            mPrivate[i + 1][j - 1] = '3';
                        }
                        else if (mPrivate[i + 1][j - 1] == '3') {
                            mPrivate[i + 1][j - 1] = '4';
                        }
                        else if (mPrivate[i + 1][j - 1] == '4') {
                            mPrivate[i + 1][j - 1] = '5';
                        }
                        else if (mPrivate[i + 1][j - 1] == '5') {
                            mPrivate[i + 1][j - 1] = '6';
                        }
                        else if (mPrivate[i + 1][j - 1] == '6') {
                            mPrivate[i + 1][j - 1] = '7';
                        }
                        else if (mPrivate[i + 1][j - 1] == '7') {
                            mPrivate[i + 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                        if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 17 && j == 0) {
                        if (mPrivate[i - 1][j + 1] == ' ') {
                            mPrivate[i - 1][j + 1] = '1';
                        }
                        else if (mPrivate[i - 1][j + 1] == '1') {
                            mPrivate[i - 1][j + 1] = '2';
                        }
                        else if (mPrivate[i - 1][j + 1] == '2') {
                            mPrivate[i - 1][j + 1] = '3';
                        }
                        else if (mPrivate[i - 1][j + 1] == '3') {
                            mPrivate[i - 1][j + 1] = '4';
                        }
                        else if (mPrivate[i - 1][j + 1] == '4') {
                            mPrivate[i - 1][j + 1] = '5';
                        }
                        else if (mPrivate[i - 1][j + 1] == '5') {
                            mPrivate[i - 1][j + 1] = '6';
                        }
                        else if (mPrivate[i - 1][j + 1] == '6') {
                            mPrivate[i - 1][j + 1] = '7';
                        }
                        else if (mPrivate[i - 1][j + 1] == '7') {
                            mPrivate[i - 1][j + 1] = '8';
                        }
                        if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 0 && i != 17 && j != 0 && j != 13) {
                        if (mPrivate[i + 1][j + 1] == ' ') {
                            mPrivate[i + 1][j + 1] = '1';
                        }
                        else if (mPrivate[i + 1][j + 1] == '1') {
                            mPrivate[i + 1][j + 1] = '2';
                        }
                        else if (mPrivate[i + 1][j + 1] == '2') {
                            mPrivate[i + 1][j + 1] = '3';
                        }
                        else if (mPrivate[i + 1][j + 1] == '3') {
                            mPrivate[i + 1][j + 1] = '4';
                        }
                        else if (mPrivate[i + 1][j + 1] == '4') {
                            mPrivate[i + 1][j + 1] = '5';
                        }
                        else if (mPrivate[i + 1][j + 1] == '5') {
                            mPrivate[i + 1][j + 1] = '6';
                        }
                        else if (mPrivate[i + 1][j + 1] == '6') {
                            mPrivate[i + 1][j + 1] = '7';
                        }
                        else if (mPrivate[i + 1][j + 1] == '7') {
                            mPrivate[i + 1][j + 1] = '8';
                        }
                        if (mPrivate[i][j + 1] == ' ') {
                            mPrivate[i][j + 1] = '1';
                        }
                        else if (mPrivate[i][j + 1] == '1') {
                            mPrivate[i][j + 1] = '2';
                        }
                        else if (mPrivate[i][j + 1] == '2') {
                            mPrivate[i][j + 1] = '3';
                        }
                        else if (mPrivate[i][j + 1] == '3') {
                            mPrivate[i][j + 1] = '4';
                        }
                        else if (mPrivate[i][j + 1] == '4') {
                            mPrivate[i][j + 1] = '5';
                        }
                        else if (mPrivate[i][j + 1] == '5') {
                            mPrivate[i][j + 1] = '6';
                        }
                        else if (mPrivate[i][j + 1] == '6') {
                            mPrivate[i][j + 1] = '7';
                        }
                        else if (mPrivate[i][j + 1] == '7') {
                            mPrivate[i][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j] == ' ') {
                            mPrivate[i + 1][j] = '1';
                        }
                        else if (mPrivate[i + 1][j] == '1') {
                            mPrivate[i + 1][j] = '2';
                        }
                        else if (mPrivate[i + 1][j] == '2') {
                            mPrivate[i + 1][j] = '3';
                        }
                        else if (mPrivate[i + 1][j] == '3') {
                            mPrivate[i + 1][j] = '4';
                        }
                        else if (mPrivate[i + 1][j] == '4') {
                            mPrivate[i + 1][j] = '5';
                        }
                        else if (mPrivate[i + 1][j] == '5') {
                            mPrivate[i + 1][j] = '6';
                        }
                        else if (mPrivate[i + 1][j] == '6') {
                            mPrivate[i + 1][j] = '7';
                        }
                        else if (mPrivate[i + 1][j] == '7') {
                            mPrivate[i + 1][j] = '8';
                        }
                        if (mPrivate[i - 1][j - 1] == ' ') {
                            mPrivate[i - 1][j - 1] = '1';
                        }
                        else if (mPrivate[i - 1][j - 1] == '1') {
                            mPrivate[i - 1][j - 1] = '2';
                        }
                        else if (mPrivate[i - 1][j - 1] == '2') {
                            mPrivate[i - 1][j - 1] = '3';
                        }
                        else if (mPrivate[i - 1][j - 1] == '3') {
                            mPrivate[i - 1][j - 1] = '4';
                        }
                        else if (mPrivate[i - 1][j - 1] == '4') {
                            mPrivate[i - 1][j - 1] = '5';
                        }
                        else if (mPrivate[i - 1][j - 1] == '5') {
                            mPrivate[i - 1][j - 1] = '6';
                        }
                        else if (mPrivate[i - 1][j - 1] == '6') {
                            mPrivate[i - 1][j - 1] = '7';
                        }
                        else if (mPrivate[i - 1][j - 1] == '7') {
                            mPrivate[i - 1][j - 1] = '8';
                        }
                        if (mPrivate[i][j - 1] == ' ') {
                            mPrivate[i][j - 1] = '1';
                        }
                        else if (mPrivate[i][j - 1] == '1') {
                            mPrivate[i][j - 1] = '2';
                        }
                        else if (mPrivate[i][j - 1] == '2') {
                            mPrivate[i][j - 1] = '3';
                        }
                        else if (mPrivate[i][j - 1] == '3') {
                            mPrivate[i][j - 1] = '4';
                        }
                        else if (mPrivate[i][j - 1] == '4') {
                            mPrivate[i][j - 1] = '5';
                        }
                        else if (mPrivate[i][j - 1] == '5') {
                            mPrivate[i][j - 1] = '6';
                        }
                        else if (mPrivate[i][j - 1] == '6') {
                            mPrivate[i][j - 1] = '7';
                        }
                        else if (mPrivate[i][j - 1] == '7') {
                            mPrivate[i][j - 1] = '8';
                        }
                        if (mPrivate[i - 1][j] == ' ') {
                            mPrivate[i - 1][j] = '1';
                        }
                        else if (mPrivate[i - 1][j] == '1') {
                            mPrivate[i - 1][j] = '2';
                        }
                        else if (mPrivate[i - 1][j] == '2') {
                            mPrivate[i - 1][j] = '3';
                        }
                        else if (mPrivate[i - 1][j] == '3') {
                            mPrivate[i - 1][j] = '4';
                        }
                        else if (mPrivate[i - 1][j] == '4') {
                            mPrivate[i - 1][j] = '5';
                        }
                        else if (mPrivate[i - 1][j] == '5') {
                            mPrivate[i - 1][j] = '6';
                        }
                        else if (mPrivate[i - 1][j] == '6') {
                            mPrivate[i - 1][j] = '7';
                        }
                        else if (mPrivate[i - 1][j] == '7') {
                            mPrivate[i - 1][j] = '8';
                        }
                        if (mPrivate[i - 1][j + 1] == ' ') {
                            mPrivate[i - 1][j + 1] = '1';
                        }
                        else if (mPrivate[i - 1][j + 1] == '1') {
                            mPrivate[i - 1][j + 1] = '2';
                        }
                        else if (mPrivate[i - 1][j + 1] == '2') {
                            mPrivate[i - 1][j + 1] = '3';
                        }
                        else if (mPrivate[i - 1][j + 1] == '3') {
                            mPrivate[i - 1][j + 1] = '4';
                        }
                        else if (mPrivate[i - 1][j + 1] == '4') {
                            mPrivate[i - 1][j + 1] = '5';
                        }
                        else if (mPrivate[i - 1][j + 1] == '5') {
                            mPrivate[i - 1][j + 1] = '6';
                        }
                        else if (mPrivate[i - 1][j + 1] == '6') {
                            mPrivate[i - 1][j + 1] = '7';
                        }
                        else if (mPrivate[i - 1][j + 1] == '7') {
                            mPrivate[i - 1][j + 1] = '8';
                        }
                        if (mPrivate[i + 1][j - 1] == ' ') {
                            mPrivate[i + 1][j - 1] = '1';
                        }
                        else if (mPrivate[i + 1][j - 1] == '1') {
                            mPrivate[i + 1][j - 1] = '2';
                        }
                        else if (mPrivate[i + 1][j - 1] == '2') {
                            mPrivate[i + 1][j - 1] = '3';
                        }
                        else if (mPrivate[i + 1][j - 1] == '3') {
                            mPrivate[i + 1][j - 1] = '4';
                        }
                        else if (mPrivate[i + 1][j - 1] == '4') {
                            mPrivate[i + 1][j - 1] = '5';
                        }
                        else if (mPrivate[i + 1][j - 1] == '5') {
                            mPrivate[i + 1][j - 1] = '6';
                        }
                        else if (mPrivate[i + 1][j - 1] == '6') {
                            mPrivate[i + 1][j - 1] = '7';
                        }
                        else if (mPrivate[i + 1][j - 1] == '7') {
                            mPrivate[i + 1][j - 1] = '8';
                        }
                    }
                }
            }
        }
    }
};
class hardMap : public baseMap {
private:
    char hPrivate[24][20] = { 0 };
    char hPublic[24][20] = { 0 };
public:
    hardMap() {
        mineCount = 99;
    };
    ~hardMap() {};
    void operator++() {
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 20; j++) {
                hPublic[i][j] = 'x';
            }
        }
    }
    void updateBoard(int& PlayPosx, int& PlayPosy, int action, bool& first, int& flags, int& revealed, int& gaming) {
        if (action == 1) {//w
            if (PlayPosy != 0) {
                PlayPosy--;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 2) {//a
            if (PlayPosx != 0) {
                PlayPosx--;
                drawBoard(PlayPosx, PlayPosy, flags);

            }
        }
        if (action == 3) {//s
            if (PlayPosy != 23) {
                PlayPosy++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 4) {//d
            if (PlayPosx != 19) {
                PlayPosx++;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
        }
        if (action == 5) {
            if (hPublic[PlayPosy][PlayPosx] == 'X') {
                flags++;
            }
            if (first == true) {
                while (hPrivate[PlayPosy][PlayPosx] != ' ') {
                    generateBoard(flags);
                }
                hPublic[PlayPosy][PlayPosx] = 'x';
                first = false;
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                hPublic[PlayPosy][PlayPosx] = 'x';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            if (hPrivate[PlayPosy][PlayPosx] == ' ') {
                int x = PlayPosx;
                int y = PlayPosy;
                while (x != 19 && hPrivate[y][x] == ' ') {
                    x++;
                    while (y != 23 && hPrivate[y][x] == ' ') {
                        y++;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 23 && hPrivate[y][x] == ' ') {
                    y++;
                    while (x != 19 && hPrivate[y][x] == ' ') {
                        x++;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && hPrivate[y][x] == ' ') {
                    y--;
                    while (x != 19 && hPrivate[y][x] == ' ') {
                        x++;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && hPrivate[y][x] == ' ') {
                    x--;
                    while (y != 23 && hPrivate[y][x] == ' ') {
                        y++;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 23 && hPrivate[y][x] == ' ') {
                    y++;
                    while (x != 0 && hPrivate[y][x] == ' ') {
                        x--;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                } x = PlayPosx;
                y = PlayPosy;
                while (x != 19 && hPrivate[y][x] == ' ') {
                    x++;
                    while (y != 0 && hPrivate[y][x] == ' ') {
                        y--;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && hPrivate[y][x] == ' ') {
                    y--;
                    while (x != 0 && hPrivate[y][x] == ' ') {
                        x--;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && hPrivate[y][x] == ' ') {
                    x--;
                    while (y != 0 && hPrivate[y][x] == ' ') {
                        y--;
                        hPublic[y][x] = 'x';
                    }
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 0 && hPrivate[y][x] == ' ') {
                    x--;
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 0 && hPrivate[y][x] == ' ') {
                    y--;
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (x != 19 && hPrivate[y][x] == ' ') {
                    x++;
                    hPublic[y][x] = 'x';
                }
                x = PlayPosx;
                y = PlayPosy;
                while (y != 23 && hPrivate[y][x] == ' ') {
                    y++;
                    hPublic[y][x] = 'x';
                }
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            revealed = 0;
            bool bombs = false;
            for (int i = 0; i < 24; i++) {
                for (int j = 0; j < 20; j++) {
                    if (hPublic[i][j] == 'x') {
                        revealed++;
                        if (hPrivate[i][j] == '@') {
                            bombs = true;
                        }
                    }

                }
            }
            if (bombs == true) {
                gaming = 2;
            }
            else
                if (revealed == 381) {
                    gaming = 1;
                }
        }
        if (action == 6) {
            if (flags > 0) {
                flags--;
                if (hPublic[PlayPosy][PlayPosx] == 'X') {
                    hPublic[PlayPosy][PlayPosx] = '#';
                    flags += 2;
                }
                else if (hPublic[PlayPosy][PlayPosx] == 'x') {
                    flags++;
                }
                else
                    hPublic[PlayPosy][PlayPosx] = 'X';
                drawBoard(PlayPosx, PlayPosy, flags);
            }
            else {
                if (hPublic[PlayPosy][PlayPosx] == 'X') {
                    hPublic[PlayPosy][PlayPosx] = '#';
                    flags++;
                    drawBoard(PlayPosx, PlayPosy, flags);
                }
            }
        }
        if (action == 7) {
            ++(*this);
            drawBoard(PlayPosx, PlayPosy, flags);
        }
        if (action == 8) {
            generateBoard(flags);
            first = true;
            drawBoard(PlayPosx, PlayPosy, flags);
        }
    };
    void drawBoard(int& PlayPosx, int& PlayPosy, int flags) {
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 20; j++) {
                if (hPublic[i][j] == '#' || hPublic[i][j] == 'X') {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << hPublic[i][j];
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << "  ";
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                        cout << hPublic[i][j] << "  ";
                    }
                }
                else {
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, MaroonBack);
                        cout << hPrivate[i][j];
                    }
                    else if (hPrivate[i][j] == '1') {
                        SetConsoleTextAttribute(hConsole, BlueFore);
                    }
                    else if (hPrivate[i][j] == '2') {
                        SetConsoleTextAttribute(hConsole, GreenFore);
                    }
                    else if (hPrivate[i][j] == '3') {
                        SetConsoleTextAttribute(hConsole, RedFore);
                    }
                    else if (hPrivate[i][j] == '4') {
                        SetConsoleTextAttribute(hConsole, PurpleFore);
                    }
                    else if (hPrivate[i][j] == '5') {
                        SetConsoleTextAttribute(hConsole, MaroonFore);
                    }
                    else if (hPrivate[i][j] == '6') {
                        SetConsoleTextAttribute(hConsole, NavyFore);
                    }
                    else if (hPrivate[i][j] == '7') {
                        SetConsoleTextAttribute(hConsole, LimeFore);
                    }
                    else if (hPrivate[i][j] == '8') {
                        SetConsoleTextAttribute(hConsole, YellowFore);
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, WhiteFore);
                    }
                    if (i == PlayPosy && j == PlayPosx) {
                        SetConsoleTextAttribute(hConsole, BlackBack);
                        cout << "  ";
                    }
                    else {
                        cout << hPrivate[i][j] << "  ";
                    }
                }
                if (j == 19) {
                    cout << endl;
                }
            }
        }
        SetConsoleTextAttribute(hConsole, WhiteFore);
        cout << endl;
        cout << "FLAGS: " << flags << endl;
    };
    void generateBoard(int& flags) {
        flags = mineCount;
        unsigned seed = time(0);
        srand(seed);
        vector <int> minPosX;
        vector <int> minPosY;
        int unique = 1;
        set<int>tempset;
        for (int i = 0; i < mineCount; i++) {
            tempset.insert(i);
        }
        int tempX;
        int tempY;
        while (tempset.size() > 0) {
            unique = 1;
            if (minPosX.empty() == true) {
                tempX = (rand() % 24);
                tempY = (rand() % 20);
                minPosX.push_back(tempX);
                minPosY.push_back(tempY);
            }
            while (unique > 0) {
                tempX = (rand() % 24);
                tempY = (rand() % 20);
                unique = 0;
                for (int i = 0; i < minPosX.size(); i++) {
                    for (int j = 0; j < minPosY.size(); j++) {
                        if (tempX == minPosX[i] && tempY == minPosY[i]) {
                            unique++;
                        }
                    }
                }
            }
            minPosX.push_back(tempX);
            minPosY.push_back(tempY);
            tempset.erase(tempset.begin());
        }
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 20; j++) {
                hPrivate[i][j] = ' ';
                hPublic[i][j] = '#';
                for (int x = 0; x < mineCount; x++) {
                    if (i == minPosX[x] && j == minPosY[x]) {
                        hPrivate[i][j] = '@';
                    }
                }
            }
        }
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 20; j++) {
                if (hPrivate[i][j] == '@') {
                    if (i == 0 && j == 0) {
                        if (hPrivate[i + 1][j + 1] == ' ') {
                            hPrivate[i + 1][j + 1] = '1';
                        }
                        else if (hPrivate[i + 1][j + 1] == '1') {
                            hPrivate[i + 1][j + 1] = '2';
                        }
                        else if (hPrivate[i + 1][j + 1] == '2') {
                            hPrivate[i + 1][j + 1] = '3';
                        }
                        else if (hPrivate[i + 1][j + 1] == '3') {
                            hPrivate[i + 1][j + 1] = '4';
                        }
                        else if (hPrivate[i + 1][j + 1] == '4') {
                            hPrivate[i + 1][j + 1] = '5';
                        }
                        else if (hPrivate[i + 1][j + 1] == '5') {
                            hPrivate[i + 1][j + 1] = '6';
                        }
                        else if (hPrivate[i + 1][j + 1] == '6') {
                            hPrivate[i + 1][j + 1] = '7';
                        }
                        else if (hPrivate[i + 1][j + 1] == '7') {
                            hPrivate[i + 1][j + 1] = '8';
                        }
                        if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 0 && j != 0 && j != 19) {
                        if (hPrivate[i + 1][j + 1] == ' ') {
                            hPrivate[i + 1][j + 1] = '1';
                        }
                        else if (hPrivate[i + 1][j + 1] == '1') {
                            hPrivate[i + 1][j + 1] = '2';
                        }
                        else if (hPrivate[i + 1][j + 1] == '2') {
                            hPrivate[i + 1][j + 1] = '3';
                        }
                        else if (hPrivate[i + 1][j + 1] == '3') {
                            hPrivate[i + 1][j + 1] = '4';
                        }
                        else if (hPrivate[i + 1][j + 1] == '4') {
                            hPrivate[i + 1][j + 1] = '5';
                        }
                        else if (hPrivate[i + 1][j + 1] == '5') {
                            hPrivate[i + 1][j + 1] = '6';
                        }
                        else if (hPrivate[i + 1][j + 1] == '6') {
                            hPrivate[i + 1][j + 1] = '7';
                        }
                        else if (hPrivate[i + 1][j + 1] == '7') {
                            hPrivate[i + 1][j + 1] = '8';
                        }
                        if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j] = '8';
                        }
                        if (hPrivate[i + 1][j - 1] == ' ') {
                            hPrivate[i + 1][j - 1] = '1';
                        }
                        else if (hPrivate[i + 1][j - 1] == '1') {
                            hPrivate[i + 1][j - 1] = '2';
                        }
                        else if (hPrivate[i + 1][j - 1] == '2') {
                            hPrivate[i + 1][j - 1] = '3';
                        }
                        else if (hPrivate[i + 1][j - 1] == '3') {
                            hPrivate[i + 1][j - 1] = '4';
                        }
                        else if (hPrivate[i + 1][j - 1] == '4') {
                            hPrivate[i + 1][j - 1] = '5';
                        }
                        else if (hPrivate[i + 1][j - 1] == '5') {
                            hPrivate[i + 1][j - 1] = '6';
                        }
                        else if (hPrivate[i + 1][j - 1] == '6') {
                            hPrivate[i + 1][j - 1] = '7';
                        }
                        else if (hPrivate[i + 1][j - 1] == '7') {
                            hPrivate[i + 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                    }
                    if (i != 0 && j == 0 && i != 23) {
                        if (hPrivate[i + 1][j + 1] == ' ') {
                            hPrivate[i + 1][j + 1] = '1';
                        }
                        else if (hPrivate[i + 1][j + 1] == '1') {
                            hPrivate[i + 1][j + 1] = '2';
                        }
                        else if (hPrivate[i + 1][j + 1] == '2') {
                            hPrivate[i + 1][j + 1] = '3';
                        }
                        else if (hPrivate[i + 1][j + 1] == '3') {
                            hPrivate[i + 1][j + 1] = '4';
                        }
                        else if (hPrivate[i + 1][j + 1] == '4') {
                            hPrivate[i + 1][j + 1] = '5';
                        }
                        else if (hPrivate[i + 1][j + 1] == '5') {
                            hPrivate[i + 1][j + 1] = '6';
                        }
                        else if (hPrivate[i + 1][j + 1] == '6') {
                            hPrivate[i + 1][j + 1] = '7';
                        }
                        else if (hPrivate[i + 1][j + 1] == '7') {
                            hPrivate[i + 1][j + 1] = '8';
                        }
                        if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j] = '8';
                        }
                        if (hPrivate[i - 1][j + 1] == ' ') {
                            hPrivate[i - 1][j + 1] = '1';
                        }
                        else if (hPrivate[i - 1][j + 1] == '1') {
                            hPrivate[i - 1][j + 1] = '2';
                        }
                        else if (hPrivate[i - 1][j + 1] == '2') {
                            hPrivate[i - 1][j + 1] = '3';
                        }
                        else if (hPrivate[i - 1][j + 1] == '3') {
                            hPrivate[i - 1][j + 1] = '4';
                        }
                        else if (hPrivate[i - 1][j + 1] == '4') {
                            hPrivate[i - 1][j + 1] = '5';
                        }
                        else if (hPrivate[i - 1][j + 1] == '5') {
                            hPrivate[i - 1][j + 1] = '6';
                        }
                        else if (hPrivate[i - 1][j + 1] == '6') {
                            hPrivate[i - 1][j + 1] = '7';
                        }
                        else if (hPrivate[i - 1][j + 1] == '7') {
                            hPrivate[i - 1][j + 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i == 23 && j == 19) {
                        if (hPrivate[i - 1][j - 1] == ' ') {
                            hPrivate[i - 1][j - 1] = '1';
                        }
                        else if (hPrivate[i - 1][j - 1] == '1') {
                            hPrivate[i - 1][j - 1] = '2';
                        }
                        else if (hPrivate[i - 1][j - 1] == '2') {
                            hPrivate[i - 1][j - 1] = '3';
                        }
                        else if (hPrivate[i - 1][j - 1] == '3') {
                            hPrivate[i - 1][j - 1] = '4';
                        }
                        else if (hPrivate[i - 1][j - 1] == '4') {
                            hPrivate[i - 1][j - 1] = '5';
                        }
                        else if (hPrivate[i - 1][j - 1] == '5') {
                            hPrivate[i - 1][j - 1] = '6';
                        }
                        else if (hPrivate[i - 1][j - 1] == '6') {
                            hPrivate[i - 1][j - 1] = '7';
                        }
                        else if (hPrivate[i - 1][j - 1] == '7') {
                            hPrivate[i - 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 23 && j == 19 && i != 0) {
                        if (hPrivate[i - 1][j - 1] == ' ') {
                            hPrivate[i - 1][j - 1] = '1';
                        }
                        else if (hPrivate[i - 1][j - 1] == '1') {
                            hPrivate[i - 1][j - 1] = '2';
                        }
                        else if (hPrivate[i - 1][j - 1] == '2') {
                            hPrivate[i - 1][j - 1] = '3';
                        }
                        else if (hPrivate[i - 1][j - 1] == '3') {
                            hPrivate[i - 1][j - 1] = '4';
                        }
                        else if (hPrivate[i - 1][j - 1] == '4') {
                            hPrivate[i - 1][j - 1] = '5';
                        }
                        else if (hPrivate[i - 1][j - 1] == '5') {
                            hPrivate[i - 1][j - 1] = '6';
                        }
                        else if (hPrivate[i - 1][j - 1] == '6') {
                            hPrivate[i - 1][j - 1] = '7';
                        }
                        else if (hPrivate[i - 1][j - 1] == '7') {
                            hPrivate[i - 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j - 1] == ' ') {
                            hPrivate[i + 1][j - 1] = '1';
                        }
                        else if (hPrivate[i + 1][j - 1] == '1') {
                            hPrivate[i + 1][j - 1] = '2';
                        }
                        else if (hPrivate[i + 1][j - 1] == '2') {
                            hPrivate[i + 1][j - 1] = '3';
                        }
                        else if (hPrivate[i + 1][j - 1] == '3') {
                            hPrivate[i + 1][j - 1] = '4';
                        }
                        else if (hPrivate[i + 1][j - 1] == '4') {
                            hPrivate[i + 1][j - 1] = '5';
                        }
                        else if (hPrivate[i + 1][j - 1] == '5') {
                            hPrivate[i + 1][j - 1] = '6';
                        }
                        else if (hPrivate[i + 1][j - 1] == '6') {
                            hPrivate[i + 1][j - 1] = '7';
                        }
                        else if (hPrivate[i + 1][j - 1] == '7') {
                            hPrivate[i + 1][j - 1] = '8';
                        }
                    }
                    if (i == 23 && j != 19 && j != 0) {
                        if (hPrivate[i - 1][j - 1] == ' ') {
                            hPrivate[i - 1][j - 1] = '1';
                        }
                        else if (hPrivate[i - 1][j - 1] == '1') {
                            hPrivate[i - 1][j - 1] = '2';
                        }
                        else if (hPrivate[i - 1][j - 1] == '2') {
                            hPrivate[i - 1][j - 1] = '3';
                        }
                        else if (hPrivate[i - 1][j - 1] == '3') {
                            hPrivate[i - 1][j - 1] = '4';
                        }
                        else if (hPrivate[i - 1][j - 1] == '4') {
                            hPrivate[i - 1][j - 1] = '5';
                        }
                        else if (hPrivate[i - 1][j - 1] == '5') {
                            hPrivate[i - 1][j - 1] = '6';
                        }
                        else if (hPrivate[i - 1][j - 1] == '6') {
                            hPrivate[i - 1][j - 1] = '7';
                        }
                        else if (hPrivate[i - 1][j - 1] == '7') {
                            hPrivate[i - 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i - 1][j + 1] == ' ') {
                            hPrivate[i - 1][j + 1] = '1';
                        }
                        else if (hPrivate[i - 1][j + 1] == '1') {
                            hPrivate[i - 1][j + 1] = '2';
                        }
                        else if (hPrivate[i - 1][j + 1] == '2') {
                            hPrivate[i - 1][j + 1] = '3';
                        }
                        else if (hPrivate[i - 1][j + 1] == '3') {
                            hPrivate[i - 1][j + 1] = '4';
                        }
                        else if (hPrivate[i - 1][j + 1] == '4') {
                            hPrivate[i - 1][j + 1] = '5';
                        }
                        else if (hPrivate[i - 1][j + 1] == '5') {
                            hPrivate[i - 1][j + 1] = '6';
                        }
                        else if (hPrivate[i - 1][j + 1] == '6') {
                            hPrivate[i - 1][j + 1] = '7';
                        }
                        else if (hPrivate[i - 1][j + 1] == '7') {
                            hPrivate[i - 1][j + 1] = '8';
                        }
                    }
                    if (i == 0 && j == 19) {
                        if (hPrivate[i + 1][j - 1] == ' ') {
                            hPrivate[i + 1][j - 1] = '1';
                        }
                        else if (hPrivate[i + 1][j - 1] == '1') {
                            hPrivate[i + 1][j - 1] = '2';
                        }
                        else if (hPrivate[i + 1][j - 1] == '2') {
                            hPrivate[i + 1][j - 1] = '3';
                        }
                        else if (hPrivate[i + 1][j - 1] == '3') {
                            hPrivate[i + 1][j - 1] = '4';
                        }
                        else if (hPrivate[i + 1][j - 1] == '4') {
                            hPrivate[i + 1][j - 1] = '5';
                        }
                        else if (hPrivate[i + 1][j - 1] == '5') {
                            hPrivate[i + 1][j - 1] = '6';
                        }
                        else if (hPrivate[i + 1][j - 1] == '6') {
                            hPrivate[i + 1][j - 1] = '7';
                        }
                        else if (hPrivate[i + 1][j - 1] == '7') {
                            hPrivate[i + 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                        if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j] = '8';
                        }
                    }
                    if (i == 23 && j == 0) {
                        if (hPrivate[i - 1][j + 1] == ' ') {
                            hPrivate[i - 1][j + 1] = '1';
                        }
                        else if (hPrivate[i - 1][j + 1] == '1') {
                            hPrivate[i - 1][j + 1] = '2';
                        }
                        else if (hPrivate[i - 1][j + 1] == '2') {
                            hPrivate[i - 1][j + 1] = '3';
                        }
                        else if (hPrivate[i - 1][j + 1] == '3') {
                            hPrivate[i - 1][j + 1] = '4';
                        }
                        else if (hPrivate[i - 1][j + 1] == '4') {
                            hPrivate[i - 1][j + 1] = '5';
                        }
                        else if (hPrivate[i - 1][j + 1] == '5') {
                            hPrivate[i - 1][j + 1] = '6';
                        }
                        else if (hPrivate[i - 1][j + 1] == '6') {
                            hPrivate[i - 1][j + 1] = '7';
                        }
                        else if (hPrivate[i - 1][j + 1] == '7') {
                            hPrivate[i - 1][j + 1] = '8';
                        }
                        if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }
                    }
                    if (i != 0 && i != 23 && j != 0 && j != 19) {
                        if (hPrivate[i + 1][j + 1] == ' ') {
                            hPrivate[i + 1][j + 1] = '1';
                        }
                        else if (hPrivate[i + 1][j + 1] == '1') {
                            hPrivate[i + 1][j + 1] = '2';
                        }
                        else if (hPrivate[i + 1][j + 1] == '2') {
                            hPrivate[i + 1][j + 1] = '3';
                        }
                        else if (hPrivate[i + 1][j + 1] == '3') {
                            hPrivate[i + 1][j + 1] = '4';
                        }
                        else if (hPrivate[i + 1][j + 1] == '4') {
                            hPrivate[i + 1][j + 1] = '5';
                        }
                        else if (hPrivate[i + 1][j + 1] == '5') {
                            hPrivate[i + 1][j + 1] = '6';
                        }
                        else if (hPrivate[i + 1][j + 1] == '6') {
                            hPrivate[i + 1][j + 1] = '7';
                        }
                        else if (hPrivate[i + 1][j + 1] == '7') {
                            hPrivate[i + 1][j + 1] = '8';
                        }
                        if (hPrivate[i][j + 1] == ' ') {
                            hPrivate[i][j + 1] = '1';
                        }
                        else if (hPrivate[i][j + 1] == '1') {
                            hPrivate[i][j + 1] = '2';
                        }
                        else if (hPrivate[i][j + 1] == '2') {
                            hPrivate[i][j + 1] = '3';
                        }
                        else if (hPrivate[i][j + 1] == '3') {
                            hPrivate[i][j + 1] = '4';
                        }
                        else if (hPrivate[i][j + 1] == '4') {
                            hPrivate[i][j + 1] = '5';
                        }
                        else if (hPrivate[i][j + 1] == '5') {
                            hPrivate[i][j + 1] = '6';
                        }
                        else if (hPrivate[i][j + 1] == '6') {
                            hPrivate[i][j + 1] = '7';
                        }
                        else if (hPrivate[i][j + 1] == '7') {
                            hPrivate[i][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j] == ' ') {
                            hPrivate[i + 1][j] = '1';
                        }
                        else if (hPrivate[i + 1][j] == '1') {
                            hPrivate[i + 1][j] = '2';
                        }
                        else if (hPrivate[i + 1][j] == '2') {
                            hPrivate[i + 1][j] = '3';
                        }
                        else if (hPrivate[i + 1][j] == '3') {
                            hPrivate[i + 1][j] = '4';
                        }
                        else if (hPrivate[i + 1][j] == '4') {
                            hPrivate[i + 1][j] = '5';
                        }
                        else if (hPrivate[i + 1][j] == '5') {
                            hPrivate[i + 1][j] = '6';
                        }
                        else if (hPrivate[i + 1][j] == '6') {
                            hPrivate[i + 1][j] = '7';
                        }
                        else if (hPrivate[i + 1][j] == '7') {
                            hPrivate[i + 1][j] = '8';
                        }
                        if (hPrivate[i - 1][j - 1] == ' ') {
                            hPrivate[i - 1][j - 1] = '1';
                        }
                        else if (hPrivate[i - 1][j - 1] == '1') {
                            hPrivate[i - 1][j - 1] = '2';
                        }
                        else if (hPrivate[i - 1][j - 1] == '2') {
                            hPrivate[i - 1][j - 1] = '3';
                        }
                        else if (hPrivate[i - 1][j - 1] == '3') {
                            hPrivate[i - 1][j - 1] = '4';
                        }
                        else if (hPrivate[i - 1][j - 1] == '4') {
                            hPrivate[i - 1][j - 1] = '5';
                        }
                        else if (hPrivate[i - 1][j - 1] == '5') {
                            hPrivate[i - 1][j - 1] = '6';
                        }
                        else if (hPrivate[i - 1][j - 1] == '6') {
                            hPrivate[i - 1][j - 1] = '7';
                        }
                        else if (hPrivate[i - 1][j - 1] == '7') {
                            hPrivate[i - 1][j - 1] = '8';
                        }
                        if (hPrivate[i][j - 1] == ' ') {
                            hPrivate[i][j - 1] = '1';
                        }
                        else if (hPrivate[i][j - 1] == '1') {
                            hPrivate[i][j - 1] = '2';
                        }
                        else if (hPrivate[i][j - 1] == '2') {
                            hPrivate[i][j - 1] = '3';
                        }
                        else if (hPrivate[i][j - 1] == '3') {
                            hPrivate[i][j - 1] = '4';
                        }
                        else if (hPrivate[i][j - 1] == '4') {
                            hPrivate[i][j - 1] = '5';
                        }
                        else if (hPrivate[i][j - 1] == '5') {
                            hPrivate[i][j - 1] = '6';
                        }
                        else if (hPrivate[i][j - 1] == '6') {
                            hPrivate[i][j - 1] = '7';
                        }
                        else if (hPrivate[i][j - 1] == '7') {
                            hPrivate[i][j - 1] = '8';
                        }
                        if (hPrivate[i - 1][j] == ' ') {
                            hPrivate[i - 1][j] = '1';
                        }
                        else if (hPrivate[i - 1][j] == '1') {
                            hPrivate[i - 1][j] = '2';
                        }
                        else if (hPrivate[i - 1][j] == '2') {
                            hPrivate[i - 1][j] = '3';
                        }
                        else if (hPrivate[i - 1][j] == '3') {
                            hPrivate[i - 1][j] = '4';
                        }
                        else if (hPrivate[i - 1][j] == '4') {
                            hPrivate[i - 1][j] = '5';
                        }
                        else if (hPrivate[i - 1][j] == '5') {
                            hPrivate[i - 1][j] = '6';
                        }
                        else if (hPrivate[i - 1][j] == '6') {
                            hPrivate[i - 1][j] = '7';
                        }
                        else if (hPrivate[i - 1][j] == '7') {
                            hPrivate[i - 1][j] = '8';
                        }
                        if (hPrivate[i - 1][j + 1] == ' ') {
                            hPrivate[i - 1][j + 1] = '1';
                        }
                        else if (hPrivate[i - 1][j + 1] == '1') {
                            hPrivate[i - 1][j + 1] = '2';
                        }
                        else if (hPrivate[i - 1][j + 1] == '2') {
                            hPrivate[i - 1][j + 1] = '3';
                        }
                        else if (hPrivate[i - 1][j + 1] == '3') {
                            hPrivate[i - 1][j + 1] = '4';
                        }
                        else if (hPrivate[i - 1][j + 1] == '4') {
                            hPrivate[i - 1][j + 1] = '5';
                        }
                        else if (hPrivate[i - 1][j + 1] == '5') {
                            hPrivate[i - 1][j + 1] = '6';
                        }
                        else if (hPrivate[i - 1][j + 1] == '6') {
                            hPrivate[i - 1][j + 1] = '7';
                        }
                        else if (hPrivate[i - 1][j + 1] == '7') {
                            hPrivate[i - 1][j + 1] = '8';
                        }
                        if (hPrivate[i + 1][j - 1] == ' ') {
                            hPrivate[i + 1][j - 1] = '1';
                        }
                        else if (hPrivate[i + 1][j - 1] == '1') {
                            hPrivate[i + 1][j - 1] = '2';
                        }
                        else if (hPrivate[i + 1][j - 1] == '2') {
                            hPrivate[i + 1][j - 1] = '3';
                        }
                        else if (hPrivate[i + 1][j - 1] == '3') {
                            hPrivate[i + 1][j - 1] = '4';
                        }
                        else if (hPrivate[i + 1][j - 1] == '4') {
                            hPrivate[i + 1][j - 1] = '5';
                        }
                        else if (hPrivate[i + 1][j - 1] == '5') {
                            hPrivate[i + 1][j - 1] = '6';
                        }
                        else if (hPrivate[i + 1][j - 1] == '6') {
                            hPrivate[i + 1][j - 1] = '7';
                        }
                        else if (hPrivate[i + 1][j - 1] == '7') {
                            hPrivate[i + 1][j - 1] = '8';
                        }
                    }
                }
            }
        }
    };
};

int drawMenu();
int play();
int playEasy(baseMap*& playArea);
int playMedium(baseMap*& playArea);
int playHard(baseMap*& playArea);
void howToPlay();
int game(baseMap*& playArea);
void win();
void lose();

int main()
{
    int gaming = drawMenu();
    if (gaming == 1) {
        win();
    }
    if (gaming == 2) {
        lose();
    }
}

int play() {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " -----------------------------" << endl;
    cout << "|                             |" << endl;
    cout << "|   Select game difficulity   |" << endl;
    cout << "|                             |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "1";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " - Easy                    |" << endl;
    cout << "|                             |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "2";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " - Medium                  |" << endl;
    cout << "|                             |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "3 ";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << "- Hard                    |" << endl;
    cout << "|                             |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "4 ";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << "- Back to menu            |" << endl;
    cout << "|                             |" << endl;
    cout << " -----------------------------" << endl;
    char ch;
    int gaming = 0;
    while (gaming == 0) {// 1 = 49   2 = 50   3 = 51
        if (_kbhit()) {

            ch = _getch();
            if (ch == 49) {
                baseMap* playArea;
                gaming = playEasy(playArea);
            }
            if (ch == 50) {
                baseMap* playArea;
                gaming = playMedium(playArea);
            }
            if (ch == 51) {
                baseMap* playArea;
                gaming = playHard(playArea);
            }
            if (ch == 52) {
                main();
            }
        }
    }
    if (gaming != 0) {
        if (gaming == 1) {
            return 1;
        }
        if (gaming == 2) {
            return 2;
        }
    }
}
void howToPlay() {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " --------------------------------" << endl;
    cout << "| > The point of the game is    |" << endl;
    cout << "| to find all the bombs without |" << endl;
    cout << "| exploding                     |" << endl;
    cout << "|                               |" << endl;
    cout << "| > Move your position with     |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "W A S D ";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << "keys                  | " << endl;
    cout << "|                               |" << endl;
    cout << "| > Mark bombs with ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "X";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " key       | " << endl;
    cout << "|                               |" << endl;
    cout << "| > Reveal the box with ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "F";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " key   | " << endl;
    cout << "|                               |" << endl;
    cout << "| > Numbers indicate how many   |" << endl;
    cout << "| bombs are around that number  |" << endl;
    cout << "|                               |" << endl;
    cout << "|  ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "4";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " - Back to menu             | " << endl;
    cout << "|                               |" << endl;
    cout << " -------------------------------" << endl;
    char ch;
    while (1) {// 1 = 49   2 = 50   3 = 51
        if (_kbhit()) {

            ch = _getch();
            if (ch == 52) {
                main();
            }
        }
    }
}
int drawMenu() {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " ----------------------------" << endl;
    cout << "|         ";
    SetConsoleTextAttribute(hConsole, TealFore);
    cout << "Mine";
    SetConsoleTextAttribute(hConsole, RedFore);
    cout << "Seeker";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << "         |" << endl;
    cout << "|                            |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "1";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " - Play                   |" << endl;
    cout << "|                            |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "2";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << " - How to Play            |" << endl;
    cout << "|                            |" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, GreenFore);
    cout << "3 ";
    SetConsoleTextAttribute(hConsole, WhiteFore);
    cout << "- Exit                   |" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "|  Created by Arnas Pipinis  |" << endl;
    cout << " ----------------------------" << endl;
    char ch;
    int gaming = 0;
    while (gaming == 0) {// 1 = 49   2 = 50   3 = 51
        if (_kbhit()) {

            ch = _getch();
            if (ch == 49) {
                gaming = play();
            }
            if (ch == 50) {
                howToPlay();
            }
            if (ch == 51) {
                system("cls");
                exit(1);
            }
        }
    }
    if (gaming != 0) {
        if (gaming == 1) {
            return 1;
        }
        if (gaming == 2) {
            return 2;
        }
    }
}
int playEasy(baseMap*& playArea) {
    system("cls");
    easyMap map;
    playArea = &map;
    int x = game(playArea);
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
}
int playMedium(baseMap*& playArea) {
    system("cls");
    mediumMap map;
    playArea = &map;
    int x = game(playArea);
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
}
int playHard(baseMap*& playArea) {
    system("cls");
    hardMap map;
    playArea = &map;
    int x = game(playArea);
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
}
int game(baseMap*& playArea) {
    int x(0), y(0);
    int flags(0);
    int revealed(0);
    playArea->generateBoard(flags);
    playArea->drawBoard(x, y, flags);
    char ch;
    bool firstMove = true;
    int gaming = 0;
    while (1) {//W A S D  -  Movement    F  -  Reveal tile    X  -  Mark bomb
        if (_kbhit()) {
            ch = _getch();// W = 119,87  A = 65,97  S = 115,83  D = 100,68  F = 102,70  X = 120,88
            if (ch == 119 || ch == 87) {
                playArea->updateBoard(x, y, 1, firstMove, flags, revealed, gaming);
                //cout << x << " " << y << endl;
            }
            if (ch == 65 || ch == 97) {
                playArea->updateBoard(x, y, 2, firstMove, flags, revealed, gaming);
                //cout << x << " " << y << endl;
            }
            if (ch == 115 || ch == 83) {
                playArea->updateBoard(x, y, 3, firstMove, flags, revealed, gaming);
                //cout << x << " " << y << endl;

            }
            if (ch == 100 || ch == 68) {
                playArea->updateBoard(x, y, 4, firstMove, flags, revealed, gaming);
                //cout << x << " " << y << endl;

            }
            if (ch == 102 || ch == 70) {
                playArea->updateBoard(x, y, 5, firstMove, flags, revealed, gaming);
                if (gaming != 0) {
                    if (gaming == 1) {
                        return gaming;
                    }
                    if (gaming == 2) {
                        playArea->updateBoard(x, y, 7, firstMove, flags, revealed, gaming);
                        system("pause");
                        return gaming;
                    }
                }
            }
            if (ch == 120 || ch == 88) {
                //cout << "MARK" << endl;
                playArea->updateBoard(x, y, 6, firstMove, flags, revealed, gaming);

            }
            if (ch == '0') {
                playArea->updateBoard(x, y, 7, firstMove, flags, revealed, gaming);
            }
            if (ch == '9') {
                playArea->updateBoard(x, y, 8, firstMove, flags, revealed, gaming);

            }
        }
    }
}
void win() {
    char ch;
    string name;
    int age;
    system("cls");
    cout << "You win!" << endl;
    cout << "Enter your name and age: ";
    cin >> name;
    cin.exceptions(ios_base::failbit); // throw on rejected input
    try {
        // some code
        int age;
        cin >> age;
        // some more code
    }
    catch (const ios_base::failure& e) {
        cout << "Not age!\n";
    }
    map <string, int> score;
    score.insert(pair<string, int>(name, age));
    cout << "Do you want to restart?" << endl << endl;
    cout << "y - yes" << endl;
    cout << "n - no" << endl;
    while (1) {
        if (_kbhit) {
            ch = _getch();
            if (ch == 'y' || ch == 'Y') {
                main();
            }
            if (ch == 'N' || ch == 'n') {
                exit(1);
            }
        }
    }
    exit(1);
}
void lose() {
    char ch;
    system("cls");
    cout << "You lose" << endl;
    cout << "Do you want to restart?" << endl << endl;
    cout << "y - yes" << endl;
    cout << "n - no" << endl;
    while (1) {
        if (_kbhit) {
            ch = _getch();
            if (ch == 'y' || ch == 'Y') {
                main();
            }
            if (ch == 'N' || ch == 'n') {
                exit(1);
            }
        }
    }
}