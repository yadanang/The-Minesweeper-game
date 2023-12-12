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
// �����Ϣ�ṹ��
typedef struct {
	char name[MAX_NAME_LENGTH];
	unsigned int seconds;
} Player;

time_t start, end;
double elapsed_time;

char playerName[MAX_NAME_LENGTH];
double seconds;

//��������
void initialization(char initi[ROWS][COLS], int rows, int cols, char set);
//���̵Ĵ�ӡ
void Print_chessboard(char print[ROWS][COLS], int row, int col);
//������
void Lay_mines(char mine[ROWS][COLS], int row, int col);
//�Ų���
void screening(char show[ROWS][COLS], char nime[ROWS][COLS], int row, int col);



// game.h
void game();

// ���а�������
void displayLeaderboard();
void updateLeaderboard(const char* playerName, double seconds);

void clearLeaderboard();
