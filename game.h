#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define EASY_COUNT 10
#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2

//函数声明
void initialization(char initi[ROWS][COLS], int rows, int cols, char set);
//棋盘的打印
void Print_chessboard(char print[ROWS][COLS], int row, int col);
//布置雷
void Lay_mines(char mine[ROWS][COLS], int row, int col);
//排查雷
void screening(char show[ROWS][COLS], char nime[ROWS][COLS], int row, int col);



// game.h
void game();

