#include <iostream>
#include <windows.h>
#include <deque>
#include <cstdlib>
using namespace std;

char coordinateGrid[11][11];
int mapSize = 10, lx = 5, ly = 5, snakeLenght = 5, randAppleSpawnX = rand() % 10, randAppleSpawnY = rand() % 10, ay = rand() % 10, ax = rand() % 10;
deque<int> prevPosX = {5, 4, 3, 2, 1}, prevPosY = {5, 5, 5, 5, 5};

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void appleSpawn() {
    do {
        randAppleSpawnX = rand() % 10;
        randAppleSpawnY = rand() % 10;
    } while (coordinateGrid[randAppleSpawnY][randAppleSpawnX] != '.');
    ax = randAppleSpawnX;
    ay = randAppleSpawnY;
}

void createGrid() {
    COORD cursorPos = {0, 0};
    SetConsoleCursorPosition(consoleHandle, cursorPos); // Move cursor to the top-left corner

    for (int x = 0; x <= mapSize; ++x) {
        for (int y = 0; y <= mapSize; ++y) {
            coordinateGrid[x][y] = '.';
        }
    }
    for (int i = 0; i < snakeLenght; ++i) {
        coordinateGrid[prevPosY[i]][prevPosX[i]] = 'O';
    }
    coordinateGrid[ay][ax] = 'A';
    for (int x = 0; x <= mapSize; ++x) {
        for (int y = 0; y <= mapSize; ++y) {
            cout << ' ' << coordinateGrid[x][y] << ' ';
            if (y == mapSize) cout << "\n";
        }
    }
}

void moveSnake(int h, int v) {
    int currentPosX = prevPosX.front() + h;
    int currentPosY = prevPosY.front() + v;
    if (coordinateGrid[currentPosY][currentPosX] == 'A') {
        snakeLenght++;
        appleSpawn();
    }
    if (currentPosX < 0 || currentPosX > mapSize || currentPosY < 0 || currentPosY > mapSize) {
        cout << "Game Over. Snake hit the wall.\n";
        Sleep(10000);
        exit(0);
    }
    for (int i = 1; i < snakeLenght; ++i)
        if (prevPosX[i] == currentPosX && prevPosY[i] == currentPosY) {
            cout << "Game Over. You ran into yourself.\n";
            Sleep(10000);
            exit(0);
        }

    prevPosX.push_front(currentPosX);
    prevPosY.push_front(currentPosY);

    if (prevPosX.size() > snakeLenght) prevPosX.pop_back();
    if (prevPosY.size() > snakeLenght) prevPosY.pop_back();
}

int main() {
    int h = 1, v = 0;
    system("cls");
    createGrid();
    while (true) {
        if (GetAsyncKeyState('W') & 0x8000 && v != 1) { h = 0; v = -1; }
        if (GetAsyncKeyState('S') & 0x8000 && v != -1) { h = 0; v = 1; }
        if (GetAsyncKeyState('A') & 0x8000 && h != 1) { v = 0; h = -1; }
        if (GetAsyncKeyState('D') & 0x8000 && h != -1) { v = 0; h = 1; }

        Sleep(100);
        moveSnake(h, v);
        createGrid();
    }
}
