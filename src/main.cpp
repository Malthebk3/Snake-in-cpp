#include <iostream>
#include <windows.h>
#include <deque>
using namespace std;

char coordinateGrid[11][11];
int mapSize = 10, lx = 5, ly = 5, snakeLenght = 5;
deque<int> prevPosX = {5, 4, 3, 2, 1}, prevPosY = {5, 5, 5, 5, 5};
int randAppleSpawnX = rand() % 10;
int randAppleSpawnY = rand() % 10;

void createGrid() {
    for (int x = 0; x <= mapSize; ++x) {
        for (int y = 0; y <= mapSize; ++y) {
            coordinateGrid[x][y] = '.';
        }
    }
    for (int i = 0; i < snakeLenght; ++i) {
        coordinateGrid[prevPosY[i]][prevPosX[i]] = 'O';
    }
    for (int x = 0; x <= mapSize; ++x) {
        for (int y = 0; y <= mapSize; ++y) {
            cout << ' ' << coordinateGrid[x][y] << ' ';
            if (y == mapSize) cout << "\n";
        }
    }
}

void appleSpawn(){
    int ay = randAppleSpawnY;
    int ax = randAppleSpawnX;
    if((coordinateGrid[randAppleSpawnY][randAppleSpawnX] = '.')||(coordinateGrid[ay][ax] = 'A')){
                coordinateGrid[ay][ax] = 'A';
    }
    else { 
            randAppleSpawnX = rand() % 10;
            randAppleSpawnY = rand() % 10;
            ax = randAppleSpawnX;
            ay = randAppleSpawnY;
    } 
}

void moveSnake(int h, int v) {
    int currentPosX = prevPosX.front() + h;
    int currentPosY = prevPosY.front() + v;
    if((coordinateGrid[currentPosY][currentPosX] = 'A')){
        snakeLenght = snakeLenght + 1;
    }
    if (currentPosX < 0 || currentPosX > mapSize || currentPosY < 0 || currentPosY > mapSize) {
        cout << "Game Over. Snake hit the wall.\n";
        Sleep(10000);
        exit(0);
    }
    for (int i = 1; i < snakeLenght; ++i) if (prevPosX[i] == prevPosX.front() && prevPosY[i] == prevPosY.front()) {
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
    createGrid();
    while (true) {
        cout << " Press WASD to move:" << endl;
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                char keyChar = static_cast<char>(keyCode);
                if (keyChar == 'W' && v != 1) { h = 0; v = -1; }
                if (keyChar == 'S' && v != -1) { h = 0; v = 1; }
                if (keyChar == 'A' && h != 1) { v = 0; h = -1; }
                if (keyChar == 'D' && h != -1) { v = 0; h = 1; }
            }
        }
        Sleep(100);
        system("cls");
        moveSnake(h, v);
        appleSpawn();
        createGrid();
    }
}

