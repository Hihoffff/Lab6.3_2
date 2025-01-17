#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;


struct team {
	char name[50];
	char trainer[50];
	int wins;
};

void tempFile(FILE* input, FILE* inputTemp);
double findMiddleVal(FILE* file);
void check(FILE* inputTemp, FILE* outputTemp, double middleVal);
void result(FILE* outputTemp, FILE* output);
//найти комманду с наибольшим кол-вом побед у заданного тренера
void findTeam(FILE* inputTemp, char w[50], int& num, int& winsMax, int& cur);
void startData(FILE* inputTemp, char w[50], int& num, int& winsMax, int& cur);
void zashita(FILE* file, FILE* res, int num);
