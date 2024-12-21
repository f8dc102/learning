/*
 * =====================================================================================
 *
 *       Filename:  rotating.c
 *
 *    Description:  Rotating Shape
 *
 *        Version:  1.0
 *        Created:  05/08/23 16:23:25
 *       Compiler:  gcc
 *
 *         Author:  정재윤 (@__77.4_), 
 *   Organization:  YONSEI UNIVERSITY
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

/*
 * Function Declaration
 */
void printFuncDesc(void);
void clearScreen(void);
int rotatingDonut(void);
int rotatingCube(void);

/*
 * Entry Point
 */
int main(void) {
    int funcNum = 0;

    clearScreen();
    printf("============================\n");
    printFuncDesc();
    printf("\nSelect Function: "); scanf("%d", &funcNum);
    printf("============================\n\n");

    switch (funcNum) {
        case 1: rotatingCube(); break;
        case 2: rotatingDonut(); break;
        default : return 0; 
    }

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printFuncDesc() {
    printf("1. rotatingCube\n");
    printf("2. rotatingDonut\n");
    printf("0. Exit\n");
}

/*
 * rotateCube
 */
float A, B, C;
float x, y, z;
float K1 = 40;
float cubeWidth = 20;
float zBuffer[160 * 44];
float horizontalOffset;
float incrementSpeed = 0.7;

char buffer[160 * 44];

int width = 160, height = 44;
int distanceFromViewPoint = 128;
int backgroundAscii = ' ';
int xPos, yPos, idx;

// Function Declaration
float calXPos(int i, int j, int k);
float calYPos(int i, int j, int k);
float calZPos(int i, int j, int k);
void calForSurface(float cubeX, float cubeY, float cubeZ, int ch);

int rotatingCube(void) {
    printf("\x1b[2J");

    while (1) {
        memset(buffer, backgroundAscii, width * height);
        memset(zBuffer, 0, width * height * 4);
        cubeWidth = 20;
        horizontalOffset = -2 * cubeWidth;

        // first cube
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                calForSurface(cubeX, cubeY, -cubeWidth, '@');
                calForSurface(cubeWidth, cubeY, cubeX, '$');
                calForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calForSurface(-cubeX, cubeY, cubeWidth, '#');
                calForSurface(cubeX, -cubeWidth, -cubeY, ';');
                calForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        cubeWidth = 10;
        horizontalOffset = 1 * cubeWidth;

        // second cube
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                calForSurface(cubeX, cubeY, -cubeWidth, '@');
                calForSurface(cubeWidth, cubeY, cubeX, '$');
                calForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calForSurface(-cubeX, cubeY, cubeWidth, '#');
                calForSurface(cubeX, -cubeWidth, -cubeY, ';');
                calForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }
        cubeWidth = 5;
        horizontalOffset = 8 * cubeWidth;

        // third cube
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                calForSurface(cubeX, cubeY, -cubeWidth, '@');
                calForSurface(cubeWidth, cubeY, cubeX, '$');
                calForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calForSurface(-cubeX, cubeY, cubeWidth, '#');
                calForSurface(cubeX, -cubeWidth, -cubeY, ';');
                calForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        printf("\x1b[H");

        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.05;
        B += 0.05;
        C += 0.01;

        usleep(8000 * 2);
    }

    return 0;
}

float calXPos(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
        j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float calYPos(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
        j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
        i * cos(B) * sin(C);
}

float calZPos(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = calXPos(cubeX, cubeY, cubeZ); 
    y = calYPos(cubeX, cubeY, cubeZ);
    z = calZPos(cubeX, cubeY, cubeZ);

    int ooz = 1 / z;

    xPos = (int) (width / 2 + horizontalOffset + K1 * ooz * x  * 2);
    yPos = (int) (height / 2 + K1 * ooz * y);
    
    idx = xPos + yPos * width;

    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

/*
 * rotateDonut
 */
int rotatingDonut(void) {
    int k;
    char b[1760];
    float A = 0, B = 0, i, j, z[1760];

    printf("\x1b[2J");

    for( ; ; ) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        for(j = 0; 6.28 > j; j += 0.07) {
            for(i = 0; 6.28 > i; i += 0.02) {
                float sini = sin(i),
                      cosj = cos(j),
                      sinA = sin(A),
                      sinj = sin(j),
                      cosA = cos(A),
                      cosi = cos(i),
                      cosB = cos(B),
                      sinB = sin(B),
                      cosj2 = cosj + 2,
                      mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5),
                      t = sini * cosj2 * cosA - sinj * sinA;
                
                int x = 40 + 30 * mess * (cosi * cosj2 * sinB - t * sinB),
                    y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
                    o = x + 80 * y,
                    N = 8 * ((sinj * sinA - sini * cosj * cosA) \
                            * cosB -sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

                if (y < 22 && y > 0 && x > 0 && x < 80 && mess > z[o]) {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }
        
        system("clear");

        for(k = 0; k < 1761; k++)
            putchar(k % 80 ? b[k] : 10);
        
        A += 0.08;
        B += 0.02;
    }

    return 0;
}
