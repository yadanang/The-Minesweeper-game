#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define EASY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

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

