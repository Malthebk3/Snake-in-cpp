#include <iostream>
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
        cout << "\n" << "Type direction to move" << "\n" << ">";
        string movement;
        cin >> movement;
        int h = 0;
        int v = 0;
        if(movement == "up"){v = -1;}
        if(movement == "down"){v = 1;}
        if(movement == "left"){h = -1;}
        if(movement == "right"){h = 1;}
        system("cls");
        createGrid(h, v);
    }
}
