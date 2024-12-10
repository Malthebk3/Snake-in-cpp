#include <iostream>
using namespace std;

string coordinateGrid[11][11];
char coordinateGrid[11][11];
int mapSize = 10;

void createGrid() {
    for(int x = 0; x <= 10; ++x) {
        for(int y = 0; y <= 10; ++y) {
void createGrid(int mx = 404, int my = 404) {

            coordinateGrid[x][y] = " x ";
            coordinateGrid[x][y] = "x";
            cout << coordinateGrid[x][y];
    int lx = 5;
    int ly = 5;

    if(mx && my == 404) {
        goto firstSkip;
    }
    if(mx != 404) {
        lx + mx;
    }
    if(my != 404) {
        ly + my;
    }

    firstSkip:
    for(int x = 0; x <= mapSize; ++x) {
        for(int y = 0; y <= mapSize; ++y) {

            coordinateGrid[x][y] = 'x';
            coordinateGrid[lx][ly] = 'O';
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
        createGrid(1, 404);
        cout << "\n" << "Type direction to move" << "\n" << ">";
        string penis;
        cin >> penis;
    }
}
