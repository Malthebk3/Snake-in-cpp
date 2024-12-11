#include <iostream>
#include <windows.h>
using namespace std;

char coordinateGrid[11][11];
int mapSize = 10;
int lx = 5;
int ly = 5;
int currentPosX = 0;
int currentPosY = 0;

void createGrid(int mx = 0, int my = 0) {
    currentPosX = currentPosX + mx;
    currentPosY = currentPosY + my;
    for(int x = 0; x <= mapSize; ++x) {
        for(int y = 0; y <= mapSize; ++y) {
            coordinateGrid[x][y] = 'x';
            coordinateGrid[ly + currentPosY][lx + currentPosX] = 'O';
            cout << ' ' << coordinateGrid[x][y] << ' ';
            if(y == 10) {
                cout << "\n";
            }
        }
    }
}



int main() {
    createGrid();
    while(true) { 
        int h = 0;
        int v = 0;
        cout << " Press WASD to move:" << endl;
            for (int keyCode = 0; keyCode < 256; ++keyCode) {
                if (GetAsyncKeyState(keyCode) & 0x8000) {
                    // Convert the key code to ASCII character
                    char keyChar = static_cast<char>(keyCode);
                    //cout << "Pressed Key: " << keyChar
                     //<< " (ASCII value: " << keyCode << ")"
                     //<< endl;
                    if(keyChar == 'W'){v = -1;}
                    if(keyChar == 'S'){v = 1;}
                    if(keyChar == 'A'){h = -1;}
                    if(keyChar == 'D'){h = 1;} 
                }
            }

        // Add a small delay to avoid high CPU usage
        Sleep(100);
           
        system("cls");
        createGrid(h, v);
    } 
}
