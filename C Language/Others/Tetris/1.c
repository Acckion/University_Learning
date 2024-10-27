#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 12
#define HEIGHT 18

int field[HEIGHT][WIDTH] = {0};
int score = 0;

// Tetromino shapes
int shapes[7][4][4] = {
    {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
    {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
    {{0,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,0,0}},
    {{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
    {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
    {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
    {{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}}
};

int currentPiece[4][4];
int currentX = WIDTH / 2 - 2;
int currentY = 0;

void drawField() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
}

int checkCollision() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currentPiece[i][j]) {
                if (currentX + j < 0 || currentX + j >= WIDTH || currentY + i >= HEIGHT || field[currentY + i][currentX + j])
                    return 1;
            }
        }
    }
    return 0;
}

void rotatePiece() {
    int temp[4][4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = currentPiece[3-j][i];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            currentPiece[i][j] = temp[i][j];
}

void newPiece() {
    currentX = WIDTH / 2 - 2;
    currentY = 0;
    int shapeIndex = rand() % 7;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            currentPiece[i][j] = shapes[shapeIndex][i][j];
}

void lockPiece() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (currentPiece[i][j])
                field[currentY + i][currentX + j] = 1;
}

void clearLines() {
    for (int i = HEIGHT - 1; i >= 0; i--) {
        int lineFilled = 1;
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == 0) {
                lineFilled = 0;
                break;
            }
        }
        if (lineFilled) {
            for (int k = i; k > 0; k--)
                for (int j = 0; j < WIDTH; j++)
                    field[k][j] = field[k-1][j];
            score += 100;
        }
    }
}

int main() {
    srand(time(0));
    newPiece();

    while (1) {
        drawField();

        if (_kbhit()) {
            char key = _getch();
            int oldX = currentX;
            int oldY = currentY;

            switch (key) {
                case 'a': currentX--; break;
                case 'd': currentX++; break;
                case 's': currentY++; break;
                case 'w': rotatePiece(); break;
                case 'q': exit(0);
            }

            if (checkCollision()) {
                currentX = oldX;
                currentY = oldY;
            }
        }

        currentY++;
        if (checkCollision()) {
            currentY--;
            lockPiece();
            clearLines();
            newPiece();
            if (checkCollision()) {
                printf("Game Over!\n");
                break;
            }
        }

        Sleep(200);  // Delay to control game speed
    }

    return 0;
}