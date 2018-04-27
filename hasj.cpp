#include <iostream>
#include <string>
using namespace std;

int main() {
    int M, N;
    char currentBlock;
    int currentPosX;
    int currentPosY;
    int startPosX;
    int startPosY;
    int finishPosX;
    int finishPosY;
    int finder;
    string map[100];
    string result = "";

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> map[i];
    }

    // Find start and end point in map
    for (int i = 0; i < M; i++) {
        finder = map[i].find('S');
        if (finder != -1) {
            currentPosX = startPosX = finder;
            currentPosY = startPosY = i;
            currentBlock = 'S';
        }

        finder = map[i].find('E');
        if (finder != -1) {
            finishPosX = finder;
            finishPosY = i;
        }
    }
    while (currentBlock != 'E') {
        if (currentPosX > 0 && (map[currentPosY][currentPosX - 1] == '.' || map[currentPosY][currentPosX - 1] == 'E')) {
            map[currentPosY][currentPosX] = '-';
            currentPosX--;
            result.append("L");
            currentBlock = map[currentPosY][currentPosX];
        } else if (currentPosX < N-1 && (map[currentPosY][currentPosX + 1] == '.' || map[currentPosY][currentPosX + 1] == 'E')) {
            map[currentPosY][currentPosX] = '-';
            currentPosX++;
            result.append("R");
            currentBlock = map[currentPosY][currentPosX];
        } else if (currentPosY > 0 && (map[currentPosY - 1][currentPosX] == '.' || map[currentPosY - 1][currentPosX] == 'E')) {
            map[currentPosY][currentPosX] = '-';
            currentPosY--;
            result.append("U");
            currentBlock = map[currentPosY][currentPosX];
        } else if (currentPosY < M-1 && (map[currentPosY + 1][currentPosX] == '.' || map[currentPosY + 1][currentPosX] == 'E')) {
            map[currentPosY][currentPosX] = '-';
            currentPosY++;
            result.append("D");
            currentBlock = map[currentPosY][currentPosX];
        }
    }

    cout << result << endl;

}