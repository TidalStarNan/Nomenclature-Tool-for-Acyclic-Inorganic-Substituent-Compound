#pragma once
#include <Windows.h>
#include <conio.h>

void render(short pos[100][4], short len, short poi[1][2]);
void nomenclature(short pos[100][4], short len);
void output(short pos[100][4], short len);
void input(short pos[100][4], short& len);

void notice()
{
	Sleep(500);
	while (_kbhit()) { (void)_getch(); }
}

void check_x(short pos[100][4], short& len, short poi[1][2]);
void check_c(short pos[100][4], short poi[1][2]);
void check_v(short pos[100][4], short& len, short poi[1][2]);
void check_b(short pos[100][4], short& len, short poi[1][2]);
void check_q(short pos[100][4], short poi[1][2]);
void check_num(short pos[100][4], short& len, short poi[1][2], short key);