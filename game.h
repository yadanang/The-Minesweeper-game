#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define EASY_COUNT 80
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
// 玩家信息结构体
typedef struct {
	char name[MAX_NAME_LENGTH];
	unsigned int seconds;
} Player;

time_t start, end;
double elapsed_time;

char playerName[MAX_NAME_LENGTH];
double seconds;

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

// 排行榜函数声明
void displayLeaderboard();
void updateLeaderboard(const char* playerName, double seconds);

void clearLeaderboard();
