#include <iostream>
using namespace std;

string coordinateGrid[11][11];
char coordinateGrid[11][11];

void createGrid() {
    for(int x = 0; x <= 10; ++x) {
        for(int y = 0; y <= 10; ++y) {

            coordinateGrid[x][y] = " x ";
            coordinateGrid[x][y] = "x";
            cout << coordinateGrid[x][y];
            if(y == 10) {
                cout << "\n";
            }
        }
    }
}

int main() {
    createGrid();
}
